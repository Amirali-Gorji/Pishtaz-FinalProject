# FinalProject
What is needed to be installed:\
1-wget 
make sure to install wget package in linux\
command : sudo apt install wget

2-libpq.h in C program:\
after installing libpq with: \ 
sudo apt-get install libpq-dev \
MAKE SURE that include directory -> "/usr/include/postgresql" and library -> "/usr/lib/postgresql"\
exist in your system.

3-Potgres Database 
in this program we use a PostgreSQL and a Database named fpdb,
first of all install postgreSQL by following this link:\
https://www.postgresqltutorial.com/install-postgresql-linux/
if you run debian based OS run: \
sudo apt-get install postgresql

4-Create a New Role in user DataBase:\
sudo -u postgres createuser finalp
then run : \
sudo -u postgres psql postgres \
to loggin as postgres role \
after that enter : \
alter user finalp with password '12345678' \
in order to set password to 12345678
it's possible that this role hasn't login permition \
to make it possibel for finalp enter: \
alter role finalp with login;

5-Create fpdb Database:\
after creating database user (role) run below command : \
sudo -u postgres createdb fpdb --owner finalp


How to start up the program:
#run with sudo 

