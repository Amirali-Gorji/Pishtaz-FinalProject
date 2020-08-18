#include<stdio.h>

//#include</usr/include/postgresql/libpq-fe.h>

#include<libpq-fe.h>

#include<stdlib.h>




int main() {
    
    PGconn *conn = PQconnectdb("user=finalp password=12345678 dbname=fpdb hostaddr = 127.0.0.1 port = 5432");

    
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


 if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
    }


    return 0;
}