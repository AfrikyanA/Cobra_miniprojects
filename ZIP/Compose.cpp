#include <iostream>
#include "Compose.h"

Compose::Compose(const std::string& inputString)
: m_inputString(inputString)
{}

//Compose::Compose() = default;
Compose::~Compose() = default;

void Compose::compose(const std::string& fileName){
    
    m_file.open(fileName);

    std::string cashedString;

    int countOfSame = 1;
    for (int i = 0; i < m_inputString.size(); ++i){
        
    }
    m_file << cashedString;  
    m_file.close();
}


void Compose::decompose(const std::string& fileName){
    
    m_file.open(fileName);
    std::string deCashedString;
    std::string tmpString;

    while (m_file.good()){
        m_file >> tmpString;
        deCashedString += tmpString;
    }
    tmpString = "";

    for (int i = 0; i < deCashedString.size(); i += 2){
        int countOfSame = deCashedString[i+1];
        while (countOfSame--){
            tmpString += deCashedString[i];
        }
    }
    std::cout << tmpString;

    m_file.close();

}