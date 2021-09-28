#include <fstream>
#include <sqlite3.h>
#include <iostream>


#pragma once

class database{

    private:
	    int rc;
        sqlite3 *db;
        char *zErrMsg = 0;

        //callback for sqlite
   	    static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
		    int i;
	  	    for(i = 0; i<argc; i++) {
   		    	printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	  	    }

  	  	    printf("\n");
	  	    return 0;
		} 

    public: 
   

   
        // Open a new SQLITE3 Database and Createa table
        void open(std::string location){
          
            //open database
            rc = sqlite3_open(location.c_str(), &db);

            if( rc ) {
                fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
            } else {
               fprintf(stderr, "Opened database successfully\n");
            }


            //create a table
            std::string sqlTable;

            sqlTable = "CREATE TABLE PASSWORDS( " 
                        "ID INTEGER  PRIMARY KEY    AUTOINCREMENT, "
                        "WEBSITE            VARCHAR(255),        "
                        "USERNAME           VARCHAR(255)        NOT NULL, "
                        "PASSWORD           VARCHAR(255)        NOT NULL)";
            
            //execute creation
            rc = sqlite3_exec(db,sqlTable.c_str(),callback,0,&zErrMsg);

            if( rc != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
            } else {
                fprintf(stdout, "Table created successfully\n");
            }

        }

        //closes databse
        void close(){
            sqlite3_close(db);
        }

        // input variables to enter into databse table
        void insertPass(std::string website, std::string username, char * password){

            // create large string
            std::string sqlCmd = "INSERT INTO PASSWORDS(WEBSITE, USERNAME, PASSWORD) VALUES ('"
                                 + website + "','" + username + "','" + password + "');";

            zErrMsg = 0;

            //execute insert
            rc = sqlite3_exec(db,sqlCmd.c_str(),callback,0,&zErrMsg);

            if( rc != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
            } else {
                std::cout << "Entry for " << website << " Createad!\n";
            }

        }

        // Overload to allow for password generator passwords of type std::string
        void insertPass(std::string website, std::string username, std::string password){
            std::string sqlCmd = "INSERT INTO PASSWORDS(WEBSITE, USERNAME, PASSWORD) VALUES ('"
                                 + website + "','" + username + "','" + password + "');";

            zErrMsg = 0;

            rc = sqlite3_exec(db,sqlCmd.c_str(),callback,0,&zErrMsg);


            if( rc != SQLITE_OK ){
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
            } else {
                std::cout << "Entry for " << website << " Createad!\n";
            }

        }



};
