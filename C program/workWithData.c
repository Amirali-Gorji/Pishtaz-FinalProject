#include<stdio.h>

#include<libpq-fe.h>

#include<stdlib.h>

#include<dirent.h>

#include<string.h>

#include <time.h>




int main() {
    
    PGconn *conn = PQconnectdb("user=finalp password=12345678 dbname=fpdb hostaddr = 127.0.0.1 port = 5432");

    //commnad to execute in terminal to create databasae Table
    PGresult *res = PQexec(conn, "CREATE TABLE IF NOT EXISTS fp_stores_data\
    (time TIMESTAMP NOT NULL, \
    market_id INTEGER , \
    product_id INTEGER , \
    provice VARCHAR(20) NOT NULL,\
    city VARCHAR(20) NOT NULL,\
    price INT, \
    quantity INT, \
    has_sold INT,\
    UNIQUE (market_id),\
    UNIQUE (product_id),\
    CONSTRAINT pk_market_product\
    PRIMARY KEY(market_id,product_id));");

//if any error occurred print it
 if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
    }
    
    //set directory that report file are in there
    DIR* directory = opendir("..");
    struct dirent *d ;
//open the directory
    while((d = readdir(directory)) != NULL){
	//if this was report file then go in bracket
        if(strstr(d->d_name,"report-1") != NULL){
       
                //create path
                char baseDir[300] = "../";
                strcat(baseDir,d->d_name);
                
                //open file with created path(baseDir) in  read mode
                FILE *fileName = fopen(baseDir,"r");

                //go through file and get it's lines
                while(!feof(fileName)){
                char str[500];
                //fill str array with lines of text file
                fgets(str,500,fileName);
                }
              }
            }


    return 0;
}
