#include <cctype>
#include <limits>
#include <stdio.h>
#include <fstream>
#include <limits>
#include <string>
#include "../include/generate.h"
#include "../include/database.h"
#include "../include/account.h"
#include "../config.h"


void drawMenu(){

    std::cout<<"*** Main Menu ***\n" << std::endl;
    std::cout<<"---- Options ----" << std::endl;
    std::cout<<"1) Search Entry" << std::endl;
    std::cout<<"2) New Entry" << std::endl;
    std::cout<<"3) Edit Entry" << std::endl;
    std::cout<<"4) Exit\n"<< std::endl;



}

void waitInput(){
    std::cout << "\n\nPress any Enter to continue..." <<std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer before taking new
    std::cin.get();
    std::system("clear");
}
// TODO
// add encryption mechanism
// fortuna
// update search
// implement edit


int main(){

    // opens database at location and name in config.h
    account acc(database_location, name);

    // store input
    int input;

    //flag for invalid input
    bool invalid =false;

    //loop and check for input
    for(;;){
        std::cout<<"\n------- Password Manager -------" << std::endl;
        drawMenu();
        if (invalid)
            std::cout<<"Invalid input; Please enter a number." <<std::endl;

        std::cout<< "Input: ";

        //input switch
        if (std::cin >> input){
            switch(input){
                case 1:
                    acc.search();
                    waitInput();
                    break;
                case 2:
                    acc.add();
                    waitInput();
                    break;
                case 3:
                    //acc.edit();
                    waitInput();
                case 4:
                    acc.exit();
                    return 0;
            }

        } else {
            
            //clear input and display invalid
            std::system("clear");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            invalid = true;
        }
        
        
    }


};
