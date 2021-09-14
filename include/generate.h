#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <random>

class generate {

    // sets of characters for password generation
    // make this static later
    const std::string capSet = ("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    const std::string lowSet = "abcdefghijklmnopqrstuvwxyz";
    const std::string numSet = "0123456789";
    const std::string symSet = "!@#$%^&*()_+-=[]{}|;:'\",<.>/?";

    private:

        std::string password  = "";

        // Create a password
         void createPass(bool caps, bool nums, bool symb,int length){

             std::string combined = lowSet;

             combined += caps ? capSet : "";
             combined += nums ? numSet : "";
             combined += symb ? symSet : "";


            for (int i = 0; i < length; i++)
                password += combined[rand() % combined.length() + 1];
         }

    public:

        // generate password based on input param
        generate(bool capsIn, bool numsIn, bool symbIn, int length){
            std::cout << "Generating Password..." << std::endl;
            createPass(capsIn,numsIn,symbIn,length);
            std::cout << "Password Generated!" << std::endl;
        }

        //implement databse write
        void writePass(){

            std::ofstream output;
            output.open("passwords.txt");
            output << password;
            output.close();
        }
};

