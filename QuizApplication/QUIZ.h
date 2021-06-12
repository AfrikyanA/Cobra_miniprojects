#ifndef QUIZ_H
#define QUIZ_H

#include <iostream>
#include <string>
#include <fstream>

const std::string QUIT_COMMAND = "q";
const std::string FILENAME1 = "test1.txt";
const std::string FILENAME2 = "test2.txt";
const size_t MAX_QUERY_SIZE = 16;


class Quiz {
public:
    Quiz();

    void chooseMode();    
private:
    void enterQuerys();
    void answerQuerys();
    
    std::string m_currFileName;
    std::fstream m_file;
};

#endif //QUIZ_H