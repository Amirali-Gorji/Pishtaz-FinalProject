# FinalProject
What is needed to be installed:\
1-wget 
make sure to install wget package in linux\
command : sudo apt install wget

2-libpq.h in C program:\
after installing libpq with sudo apt-get install libpq-dev \
by default i set the include directory to: #include</usr/include/postgresql/libpq-fe.h> 
make sure that libpq has installed on this directory, Otherwise open C program with an editor and change the include directory

3-fpdb DataBase:\
in this program we use a PostgreSQL and a Database named fpdb,
first of all install postgreSQL by following this link:\
https://www.postgresqltutorial.com/install-postgresql-linux/ \
after that you should create a DataBase that mentioned above, so in terminal run : 
sudo -i -u postresql\
you'll be logged in to system as a user named postres  
then run :\
psql\
you can see name of data base ( by default it's postres ) \ 
finally run ( don't forget semicolon)\
CREATE DATABASE fpdb;

How to start up the program:
#run with sudo 

gcc -Wall -Wextra -I "/usr/include/postgresql" -L "/usr/lib/postgresql" workWithData.c -lpq -o work
