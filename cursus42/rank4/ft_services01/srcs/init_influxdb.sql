CREATE DATABASE telegraf;
CREATE USER acarvaja WITH PASSWORD 'acarvaja' WITH ALL PRIVILEGES;
grant all privileges to "acarvaja";
GRANT ALL ON "telegraf" to "acarvaja";