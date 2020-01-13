#!/bin/sh
echo "--- FTPS Server ---"
echo "--- Creando fichero de log vacio ---"
touch /var/log/vsftpd.log

echo "--- Generando certificado ---"
openssl req -x509 -nodes -days 7300 -newkey rsa:2048 -subj "/C=ES/ST=Aranjuez/L=Madrid/O=42/CN=acarvaja" -keyout /etc/ssl/certs/vsftpd.pem -out /etc/ssl/certs/vsftpd.pem
chmod 600 /etc/ssl/certs/vsftpd.pem

echo "--- Añadiendo usuarios ---"
mkdir -p /ftps/empty
mkdir -p /ftps/data
addgroup admin
adduser -D --ingroup admin admin
echo "admin:pass1234" | chpasswd
echo "root:pass1234" | chpasswd

echo "--- Asignando permisos ---"
chmod 555 /ftps/empty
mkdir -p /ftps/data
chmod a-w /ftps/data
mkdir -p /ftps/data/root
chown -R root:root /ftps/data/root
mkdir -p /ftps/data/admin
chown -R admin:admin /ftps/data/admin

echo "--- Servicio FTPS en escucha... ---"
/usr/sbin/vsftpd /etc/vsftpd/vsftpd.conf &
exec "$@"