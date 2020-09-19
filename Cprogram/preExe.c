#include<libpq-fe.h>



int main() {

    PGconn *conn = PQconnectdb("user=finalp password=12345678 dbname=fpdb hostaddr = 127.0.0.1 port = 5432");

    //commnad to execute in terminal to create databasae Table

    // PGresult *res = PQexec(conn, "CREATE TABLE IF NOT EXISTS fp_stores_data\
    // (time INTEGER NOT NULL, \
    // has_sold INTEGER,\
    // quantity INTEGER, \
    // price INTEGER, \ 
    // product_id INTEGER ,\
    // market_id INTEGER ,\
    // provice VARCHAR(20) NOT NULL,\
    // city VARCHAR(20) NOT NULL,\
    // CONSTRAINT pk_market_product\
    // PRIMARY KEY(market_id,product_id));");

    PGresult *res = PQexec(conn, "CREATE TABLE IF NOT EXISTS fp_stores_data\
    (time INTEGER NOT NULL, \
    market_id INTEGER ,\
    product_id INTEGER ,\
    price INTEGER,\
    quantity INTEGER, \
    has_sold INTEGER,\
    provice VARCHAR(20) NOT NULL,\
    city VARCHAR(20) NOT NULL,\
    CONSTRAINT pk_market_product\
    PRIMARY KEY(market_id,product_id));");



    //if any error occurred print it
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "%s\n", PQerrorMessage(conn));
    }

}