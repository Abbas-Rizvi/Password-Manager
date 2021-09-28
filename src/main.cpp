#include <cctype>
#include <limits>
#include <stdio.h>
#include <fstream>
#include <string>
#include "../include/generate.h"
#include "../include/database.h"
#include "../include/account.h"
#include "../config.h"


void drawMenu(){

    std::cout<<"Main Menu\n" << std::endl;
    std::cout<<"---- Options ----" << std::endl;
    std::cout<<"1) Search Entry" << std::endl;
    std::cout<<"2) New Entry" << std::endl;
    std::cout<<"3) Edit Entry" << std::endl;
    std::cout<<"4) Export Database" << std::endl;
    std::cout<<"5) Exit\n"<< std::endl;



}


int main(){

    // opens database at location and name in config.h
    account acc(database_location, name);


    

    // store input
    int input;

    //loop and check for input
    for(;;){
        std::cout<<"\nPassword Manager" << std::endl;
        drawMenu();
        std::cout<< "Input: ";

        if (std::cin >> input){

            switch(input){
                case 1:
                    // acc.search();
                case 2:
                    acc.add();

                    break;
                case 3:
                    //acc.edit();

                case 5:
                    acc.exit();
                    return 0;
            }

        } else {

            std::cout<<"Invalid input; Please enter a number." <<std::endl;
            std::cin.clear();
            std::cin.ignore();
        }
        
        
    }


};
