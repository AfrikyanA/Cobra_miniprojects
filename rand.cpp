#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <time.h> 
#include <cctype> 

const int MIN_LETTER_FROM   = 2;
const int RANDOM_NUMBER_TO  = 7;
const char UPPERCASE_A      = 'A';
const int ASCII_UPPERCASE_Z = 90;
const int ASCII_UPPERCASE_A = 65;
const int ASCII_LOWERCASE_A = 97;
const int RANGE_A_TO_Z      = 25;
const int TIVA_ELI_HEL_VEREV_TES = 6;

std::string RandomGenerator(){
    std::string password{};

    int x = MIN_LETTER_FROM + rand() % RANDOM_NUMBER_TO;
    for (int i = 0; i < x; ++i){
        unsigned short sh = ASCII_UPPERCASE_A + rand() % RANGE_A_TO_Z; 
        char ch = sh;
        password += ch;
    }

    x = MIN_LETTER_FROM + rand() % RANDOM_NUMBER_TO; 
    for (int i = 0; i < x; ++i){
        unsigned short sh = ASCII_LOWERCASE_A + rand() % RANGE_A_TO_Z;
        char ch = sh;
        password += ch;
    }

    for (int i = 0; i < MIN_LETTER_FROM; ++i){
        unsigned short sh = (ASCII_UPPERCASE_Z+1) + rand() % TIVA_ELI_HEL_VEREV_TES; 
        char ch = sh;
        password += ch;
    }
    return password;      
}

bool isUnique(const std::string& str){
    unsigned long long table{};

    for(const auto& ch : str){
        if(table & (1LL << (ch - UPPERCASE_A))){
            return false;
        }
        else {
            table |= 1LL << (ch - UPPERCASE_A);
        }
    }
    return true;
}

bool validUppercase(const std::string& str){
    size_t validationCount{};
    for (const auto& ch : str){
        if(isalpha(ch)) 
            ++validationCount;
    }
    return validationCount >= MIN_LETTER_FROM;
}

bool validLowercase(const std::string& str){
    size_t validationCount{};
    for (const auto& ch : str){
        if(islower(ch)) 
            ++validationCount;
    }
    return validationCount >= MIN_LETTER_FROM;
}

bool validSymbol(const std::string& str){
    size_t validationCount{};
    for (const auto& ch : str){
        int a = static_cast<int>(ch);
        if(a > ASCII_Z && a < ASCII_LOWERCASE_A) 
            ++validationCount;
    }
    return validationCount == MIN_LETTER_FROM;
}

bool isOk(const std::string& str){
    if(!isUnique(str)) return true;

    return validUppercase(str) && validLowercase(str) && validSymbol(str);
}

int main(){
    srand(time(NULL));
    std::cout << "Enter number, to generate passwords: ";
    size_t x; std::cin >> x;
    while(--x){
        std::string s = RandomGenerator();
        std::cout << s << "\t" <<  std::boolalpha << isOk(s) << std::endl;
    } 
}