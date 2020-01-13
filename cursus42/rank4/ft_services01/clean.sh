#!/bin/bash
printf "\e[32mLimpiando\e[0m\n"
printf "\e[33mEliminando FTPS Server\e[0m\n"
kubectl delete -f srcs/ftps.yaml
printf "\e[33mEliminando Ingress\e[0m\n"
kubectl delete -f srcs/ingress.yaml
printf "\e[33mEliminando Ingress Controller\e[0m\n"
helm delete nginx-ingress
printf "\e[33mEliminando NGINX\e[0m\n"
kubectl delete secret ssl-keys
kubectl delete -f srcs/nginx.yaml
printf "\e[33mEliminando PHPMyAdmin\e[0m\n"
kubectl delete -f srcs/phpmyadmin.yaml
printf "\e[33mEliminando Wordpress\e[0m\n"
kubectl delete -f srcs/wordpress.yaml
printf "\e[33mEliminando MySQL\e[0m\n\n"
kubectl delete -f srcs/mysql.yaml
printf "\e[33mEliminando Grafana\e[0m\n"
helm delete grafana
printf "\e[33mEliminando InfluxDB\e[0m\n"
helm delete influxdb
printf "\e[32mTerminado\e[0m\n"