#include <stdio.h>
#include <string>
#include <iostream>
#include <random>
#include <stdlib.h>   
#include <time.h> 

#pragma once

class generate{

    // sets of characters for password generation
    // make this static later
    const std::string capSet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    const std::string lowSet = "abcdefghijklmnopqrstuvwxyz";
    const std::string numSet = "0123456789";
    const std::string symSet = "!@#$%^&*()_+-=[]{}|;:\",<.>/?";

    private:
    
        // Create a password
        std::string createPass(bool caps, bool nums, bool symb,int length){
            std::string password  = "";

             std::string combinedSet = lowSet;

             combinedSet += caps ? capSet : "";
             combinedSet += nums ? numSet : "";
             combinedSet += symb ? symSet : "";

            char randChar;

            //use seeded random
            srand (time(NULL));

            //pick random characters from the combined set
            for (int i = 0; i < length; i++){
                randChar = combinedSet[rand() % combinedSet.length() + 1];

                while (randChar == '\0')
                    randChar = combinedSet[rand() % combinedSet.length() + 1];

                password += randChar;
            }

            return password;
         }

   

    public:

        // generate password based on input param and return
        std::string generateNew(bool capsIn, bool numsIn, bool symbIn, int length){
            std::cout << "\n\nGenerating Password..." << std::endl;
            return createPass(capsIn,numsIn,symbIn,length);
        }

};