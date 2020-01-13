# --- Requisitos precios ---

# Instalar: virtualbox, docker-machine, docker, minikube, kubectl, helm, jq
# Actualizar helm: helm repo add stable https://kubernetes-charts.storage.googleapis.com; helm repo update;
# minikube status
# minikube start --cpus=4 --memory 4000 --disk-size 11000 --vm-driver virtualbox --extra-config=apiserver.service-node-port-range=1-35000
wait_for_deploy () {
	printf "\e[32mEperando por: \e[0;36m"$1"\e[0;32m...\e[0m"
	sleep 2s
	export "$1"_POD=$( kubectl get pods -l app=$1 -o custom-columns=:metadata.name | tr -d '[:space:]' )
	export POD_TEMP=${1}_POD
	while [ "$( kubectl get pod ${!POD_TEMP} -o json | jq ".status.containerStatuses[0].ready" | tr -d '[:space:]' )" != "true" ]
	do
		printf "\e[0;32m.\e[0m"
		sleep 1s
	done
	sleep 2s
	printf "\e[0;33m --> Finalizado\e[0m\n\n"
}

secure_wait () {
	printf "\n --- Espera de seguridad --- \n\e[0;32m="
	export i=1
	while [ $i -le 50 ]
	do
		sleep 0.07s
		i=$((i + 1))
		printf "="
	done
	printf "\e[0m\n✅ Tiempo de espera de seguridad finalizado.\n"
}

kubectl get all
chmod u+x clean.sh
while true; do
    read -p "Desea limpiar antes de compilar? Reponde con y o n:" yn
    case $yn in
        [Yy]* ) sh ./clean.sh; break;;
        [Nn]* ) break;;
        * ) echo "Porfavor responde: yes o no.";;
    esac
done

# Poner entorno con docker para minikube, para que kubernetes vea las imágenes construidas por docker.
eval $(minikube docker-env);

# --- Iniciar Minikube Dashboard ---
printf "0) -->Iniciando el \e[4;33mdadhboard de minikube\e[0m.\n"
open -a Terminal ./srcs/dashboard.sh
printf "\n\e[33mEspere hasta que se haya abierto una ventana nueva con el dashboard de minikube.\e[0m\n"
read -n 1 -s -r -p "Pulse enter para continuar"

# --- Desplegando servicios ---

# Guias que he seguido
# https://youtu.be/GLE71pIHUU8
# https://octoperf.com/blog/2019/09/19/kraken-kubernetes-influxdb-grafana-telegraf/
# https://www.youtube.com/watch?v=Fabdhg_WMVU
# https://medium.com/faun/total-nginx-monitoring-with-application-performance-and-a-bit-more-using-8fc6d731051b

# InfluxDB, Telegraf, Grafana
printf "\n\n1.1) --- Desplegando \e[4;33mInfluxDB\e[0m ---\n"
helm install -f srcs/influxdb.yaml influxdb stable/influxdb 
wait_for_deploy influxdb
secure_wait

printf "\n1.2) --- Desplegando \e[4;33mGrafana\e[0m ---\n"
helm install -f srcs/grafana.yaml grafana stable/grafana 
wait_for_deploy grafana
secure_wait
printf "\n\e[33mAcceda a través del dashboard de minikube e inyecte el script \e[4;33m'srcs/init_influxdb.sql'\e[0m\n"
read -n 1 -s -r -p "Pulse enter para continuar"

# MySQL, Wordpress, PhpMyAdmin
printf "\n1.3) --- Desplegando \e[4;33mMySQL\e[0m ---\n"
kubectl apply -f srcs/mysql.yaml
wait_for_deploy mysql
secure_wait

printf "\n1.4) --- Desplegando \e[4;33mhpMyAdmin\e[0m ---\n"
kubectl apply -f srcs/phpmyadmin.yaml
wait_for_deploy phpmyadmin
secure_wait

printf "\n1.5 --- Desplegando \e[4;33mWordpress\e[0m ---\n"
kubectl apply -f srcs/wordpress.yaml
wait_for_deploy wordpress
secure_wait

# NGINX, Ingress Controller
printf "\n1.6.1 --- Construyendo \e[4;33mNGINX Image\e[0m ---\n"
docker build -t nginx_ssh srcs/nginx

printf "\n1.6.2 --- Desplegando \e[4;33mDeploy NGINX\e[0m ---\n"
kubectl create secret generic ssl-keys --from-file=srcs/nginx/keys/nginx.crt --from-file=srcs/nginx/keys/nginx.key
# kubectl create secret generic ssh-keys --from-file=srcs/nginx/keys/ssh_host_dsa_key --from-file=srcs/nginx/keys/ssh_host_dsa_key.pub  --from-file=srcs/nginx/keys/ssh_host_rsa_key --from-file=srcs/nginx/keys/ssh_host_rsa_key.pub --from-file=srcs/nginx/sshd_config
# kubectl create configmap nginx-config-map --from-file=srcs/nginx/nginx.conf
sleep 1s
kubectl apply -f srcs/nginx.yaml
wait_for_deploy nginx
secure_wait

printf "\n1.7 --- Desplegando \e[4;33mIngress\e[0m ---\n"
minikube addons enable ingress
kubectl apply -f srcs/ingress.yaml
printf "\e[0;32mEsperando por: Ingress...\e[0m\n"
sleep 10s

printf "\n1.8 --- Desplegando \e[4;33mIngress Controller\e[0m ---\n"
helm install -f srcs/nginx-ingress.yaml nginx-ingress stable/nginx-ingress
#Como nginx-ingress daría error al llamar a la función de espera debido al '-', lo hago explicitamente.
printf "\e[32mEsperando por: \e[0;36mnginx-ingress\e[0;32m...\e[0m\n"
read -n 1 -s -r -p "En otro terminal comprueba (con kubectl get pods) o a través del dashboard de minikube si nginx-ingress esta listo,\
 posteriormente pulse cualquier tecla para continuar con el script." 

# FTPS Server
export KUB_IP=$(minikube ip)
printf "\n"
read -n 1 -s -r -p "Verifica que la IP in srcs/ftps/vsftpd.conf es correcta, \
y reemplaza si es necesario. Poseteriormente pulse enter"
printf "\n1.9.1 --- Construyendo \e[4;33mFTPS Image\e[0m ---\n"
docker build -t ftps_server srcs/ftps
printf "\n1.9.2 --- Desplegando \e[4;33mFTPS Server\e[0m ---\n"
kubectl apply -f srcs/ftps.yaml
wait_for_deploy ftps
secure_wait

# --------------------
# 2) Testeos

# 2.0) Para ver los diferentes servicios
kubectl get all

# 2.3) SSH
# ssh -v root@$KUB_IP -p 32022

# 2.4) FTPS Server
export MKB_IP=$(minikube ip)
printf "\e[32mDespliegue finalizado pruebe a acceder mediante la ip: \e[4;33m"$MKB_IP"\e[0m"