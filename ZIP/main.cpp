#include <iostream>
#include <string>
#include "Compose.h"

int main(){
    std::cout << "This is a \"Compress/decompress\" program"
                 "\n1-> Comp\n2-> Decomp\nChoose mode: " << std::endl;
    int choice; std::cin >> choice;
    
    std::cout << "Input file name: ";
    std::string fileName; std::cin >> fileName;

    if (choice == 1){
        
        std::cout << "Enter text: ";
        std::string inStr; std::cin >> inStr;
        Compose obj(inStr);
        obj.compose(fileName);

    }else{
        Compose obj;
        obj.decompose(fileName);
    }
}