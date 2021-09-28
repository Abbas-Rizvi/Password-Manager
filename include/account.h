#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "database.h"
#include "generate.h"
#include <unistd.h> 

class account{
    private:
        database db;
        generate generator;

    public:
        //open databse at path and name
        account(std::string database_path, std::string databse_name){
            db.open((database_path + "/" + databse_name));
        }

        void search();
        

        void add(){
            // user enters website and username
            std::cout<<"Enter Website Name: ";
            std::string website;
            std::cin >> website;

            std::cout<<"Enter Username: ";
            std::string username;
            std::cin >> username;


            // prompt for creating password
            char input;
            std::cout <<"\nDo you want to generate password? [y/n]  ";
            std::cin >> input;
            int i = 0;

            //timeout loop after 3 iterations
            while (i < 3){

                //if yes
                if (input == 'y' ||input == 'Y' || input == ' '){

                    int length;
                    std::cout <<"Enter Length: ";
                    
                    //create password of length and insert into database
                    if (std::cin >> length){
                        db.insertPass(website, username,generator.generateNew(true,true,true,length));
                        break;
                    }else{
                        std::cout <<"\ninvalid length";
                        std::cin.clear();
                    }

                // if no
                } else if (input == 'n' ||input == 'N'){

                    //prompt user to enter password and write to database
                    const char * prompt = "Enter Password: ";
                    char * password = getpass(prompt);
                    db.insertPass(website, username, password);
                    free(password);
                    break;

                // if invalid entry; max 3 iterations  
                } else {
                    i++;
                    std::cout <<"invalid entry" <<std::endl;

                    if (i < 3){
                        std::cout <<"\nDo you want to generate password? [y/n]  ";
                        std::cin >> input;
                    } else {
                        std::cout <<"\nToo many invalid entries; Returning to menu" <<std::endl;
                    }
                }
            }

            
        }

        void exit(){
            db.close();
        }

};
