#include<stdio.h>

#include<libpq-fe.h>

#include<stdlib.h>

#include<dirent.h>

#include<string.h>

#include <time.h>


int NUMBER_DATA = 8;
int LENGHT_LINE = 20;
int main() {
    
    PGconn *conn = PQconnectdb("user=finalp password=12345678 dbname=fpdb hostaddr = 127.0.0.1 port = 5432");
    //set directory that report file are in there
    DIR* directory = opendir("/tmp/final_project/");
    struct dirent *d;
    //open the directory
    //int j = 0;
    while((d = readdir(directory)) != NULL){
       
       //if(j == 1){
       // break;
      // }
	    //if this was report file then go in bracket
        if(strstr(d->d_name,"report-") != NULL){

            //create path
            char baseDir[300] = "/tmp/final_project/";
            strcat(baseDir,d->d_name);
            
            //open file with created path(baseDir) in  read mode
            FILE *fileName = fopen(baseDir,"r");

            //go through file and get it's lines
            int tmp = 0;
            char city[25] = "یهجایی";
            int toInsertCity[] = {1234,0,0};
            
            while(!feof(fileName)){
                char str[500];
                //fill str array with lines of text file
                fgets(str,500,fileName);
                
                //to split a string
                //Extract the first token
                char * token = strtok(str , ",");
                //loop through the string to extract all other tokens
                
                char info[NUMBER_DATA][20];
                int i = 0;

                //split data and save them into info array
                while( token != NULL ) {
                    char tmp[LENGHT_LINE];
                    sprintf(tmp,"%s",token);
                    //asign it to array
                    strcpy(info[i],tmp);
                    token = strtok(NULL , ",");
                    i++;
                }

                //for city_aggregation
                //time or city property has changed so INSERT old aggregations

                

                if(tmp != 0 && ( strcmp(info[2], city) != 0 || atol(info[0]) != toInsertCity[0] )){

                    char command[500]; 
                    char toIn[3][20];
                    //to convert integer into string in order to use it in insert command
                    sprintf(toIn[0],"%d",toInsertCity[0]);
                    sprintf(toIn[1],"%d",toInsertCity[1]);
                    sprintf(toIn[2],"%d",toInsertCity[2]);
                    sprintf(command,"INSERT INTO ‫‪\"fp_city_aggregation\"\n‬‬(time,city,has_sold,quantity)\nVALUES (%s,\'%s\',%s,%s);" ,
                                                toIn[0],
                                                city,
                                                toIn[1],
                                                toIn[2]);


                    
                    PGresult *res = PQexec(conn,command);
                    //store this line in ram
                    sprintf(city,"%s",info[2]);
                    toInsertCity[0] = atol(info[0]);
                    toInsertCity[1] = atol(info[3]);
                    toInsertCity[2] = atol(info[4]);
                }


                //aggregation data
                else{
                    
                    //atol will convert string to int
                    //time
                    toInsertCity[0] = atol(info[0]);
                    //city
                    sprintf(city,"%s",info[2]);
                    //has_sold
                    toInsertCity[1] = toInsertCity[1] + atol(info[3]);
                    //quantity
                    toInsertCity[2] = toInsertCity[2] + atol(info[4]);
                }

                    //creating commad to INSERT informations
                    char command[500]; 

                    sprintf(command,"INSERT INTO fp_stores_data\n(time,city,provice,has_sold,quantity,price,product_id,market_id)\nVALUES (%s,\'%s\',\'%s\',%s,%s,%s,%s,%s);" ,
                                            info[0],info[1],
                                            info[2],info[3],
                                            info[4],info[5],
                                            info[6],info[7]);


                    

                    PGresult *res = PQexec(conn,command);
                    //tmp++;
                    //if(tmp == 1500)
                       // break;

            }
        }
        //j++;
    } 
    return 0;
}
