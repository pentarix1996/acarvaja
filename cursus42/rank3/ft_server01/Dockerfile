FROM debian:buster
MAINTAINER acarvaja acarvaja@student.42madrid.com

# Requisitos previos
RUN apt-get clean all && \
apt-get -y update && \
rm -fr ./var/cache/*

# Instalación de las aplicaciones y WordPress
RUN apt-get upgrade && \
apt-get -y install curl nginx mariadb-server wget && \
apt-get -y install php php-common php-cli php-fpm php-mysql && \
curl -O https://wordpress.org/latest.tar.gz && \
tar -xvf latest.tar.gz -C /var/www/ && \
rm latest.tar.gz

#SLL instalación && configuración
RUN mkdir ~/mkcert && \
  cd ~/mkcert && \
  wget https://github.com/FiloSottile/mkcert/releases/download/v1.1.2/mkcert-v1.1.2-linux-amd64 && \
  mv mkcert-v1.1.2-linux-amd64 mkcert && \
  chmod +x mkcert && \
  ./mkcert -install && \
  ./mkcert localhost

# Configurar la base de datos el sleep es para dar tiempo a que inicie el servicio
COPY srcs/mysql-setup.sql /tmp/
COPY srcs/wp-config.php /var/www/wordpress/
COPY srcs/localhost.sql .
RUN service mysql start && \
sleep 2 && \
mysql < /tmp/mysql-setup.sql && \
rm -fr /tmp/mysql-setup.sql* && \
mysql < ./localhost.sql && \
rm -rf localhost.sql && \
service mysql stop

# Instalación PHPMyAdmin
RUN curl -O https://files.phpmyadmin.net/phpMyAdmin/4.9.2/phpMyAdmin-4.9.2-english.tar.gz && \
mkdir /var/www/wordpress/phpmyadmin && \
tar -xvzf phpMyAdmin-4.9.2-english.tar.gz --strip-components=1 -C /var/www/wordpress/phpmyadmin && \
rm -fr ./phpMyAdmin-4.9.2-english.tar.gz
COPY srcs/config.inc.php /var/www/wordpress/phpMyAdmin/

# Editar wp-config.php y dar permisos
RUN chown -R $USER:www-data /var/www/wordpress && \
chmod g+w /var/www/wordpress/wp-content && \
chmod -R g+w /var/www/wordpress/wp-content/themes && \
chmod -R g+w /var/www/wordpress/wp-content/plugins

# Configurar Nginx y PHP
COPY srcs/wordpress /etc/nginx/sites-available/
RUN ln -fs /etc/nginx/sites-available/wordpress /etc/nginx/sites-enabled/default

# Exponer puerto
EXPOSE 80 443

# Arrancar servicios
CMD service nginx start && \
service mysql start && \
service php7.3-fpm start && \
sleep infinity