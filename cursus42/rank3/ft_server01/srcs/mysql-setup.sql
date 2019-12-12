CREATE DATABASE wordpress;
CREATE USER 'acarvaja' IDENTIFIED BY 'acarvaja';
GRANT ALL PRIVILEGES ON wordpress.* TO 'acarvaja'@'localhost' IDENTIFIED BY 'acarvaja';
FLUSH PRIVILEGES;