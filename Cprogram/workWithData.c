#include<stdio.h>

#include<libpq-fe.h>

#include<stdlib.h>

#include<dirent.h>

#include<string.h>

#include <time.h>


int NUMBER_DATA = 8;

int main() {

    PGconn *conn = PQconnectdb("user=finalp password=12345678 dbname=fpdb hostaddr = 127.0.0.1 port = 5432");
    //set directory that report file are in there
    DIR* directory = opendir("..");
    struct dirent *d;
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
                int tmp = 0;
                while(!feof(fileName)){
                char str[500];
                //fill str array with lines of text file
                fgets(str,500,fileName);
                
                
                
                //to split a string
                //Extract the first token
                char * token = strtok(str, ",");
                //loop through the string to extract all other tokens
                
                    char info[NUMBER_DATA][20];
                    int i = 0;
                    while( token != NULL ) {
                        
                        char tmp[20];
                        sprintf(tmp,"%s",token);
                        //asign it to array
                        strcpy(info[i],tmp);
                        //printf(u8"%s\n", tmp ); //printing each token
                        token = strtok(NULL , ",");
                        i++;
                    }
                    

                    //creating commad to INSERT informations
                    char command[500]; 
                    // sprintf(command,"INSERT INTO fp_stores_data\n(time,city,provice,has_sold,quantity,price,product_id,market_id)\nVALUES (%s,\'%s\',\'%s\',%s,%s,%s,%s,%s);" ,
                    //                             info[0],info[1],
                    //                             info[2],info[3],
                    //                             info[4],info[5],
                    //                             info[6],info[7]);

                    sprintf(command,"INSERT INTO fp_stores_data\n(time,city,provice,has_sold,quantity,price,product_id,market_id)\nVALUES (%s,\'%s\',\'%s\',%s,%s,%s,%s,%s);" ,
                                                info[0],info[1],
                                                info[2],info[3],
                                                info[4],info[5],
                                                info[6],info[7]);

                   // printf("info in %s\n",info[2]);
                    printf("----------------------------------\n");
                    printf("command is : %s",command);
                    
                    PGresult *res = PQexec(conn,command);
                    tmp++;
                    if(tmp == 1500)
                        break;
                }
              }
            }
    return 0;

}
