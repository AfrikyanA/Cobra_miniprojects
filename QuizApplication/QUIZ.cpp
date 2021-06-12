#include "QUIZ.h"
#include <type_traits>


Quiz::Quiz() = default;

void Quiz::chooseMode(){

    std::cout << "1 -> Administrator\n2 -> Student\nChoose mode: ";
    int choice; std::cin >> choice;
    
    if (choice == 1){
        enterQuerys();
    }
    else {
        answerQuerys();
    }
}

void Quiz::enterQuerys(){
    
    std::cout << "Choose test(1,2): ";
    int choice; std::cin >> choice;
    
    switch (choice){
        case(1):
            m_currFileName = FILENAME1;
            break;
        case(2):
            m_currFileName = FILENAME1;
            break;
    }

    m_file.open(m_currFileName);

    std::string query, answer1, answer2, answer3;
    int trueAnswer;

    size_t countOfQuerys = 0;
    while(countOfQuerys++ < MAX_QUERY_SIZE){
        
        std::cout << "Enter query(q): "; std::getline(std::cin, query);
        if (query == QUIT_COMMAND){
            break;
        }

        m_file << query << std::endl;

        std::cout << "Enter 1-st answer: "; std::getline(std::cin, answer1);
        m_file << "1) " << answer1 << std::endl;

        std::cout << "Enter 2-nd answer: "; std::getline(std::cin, answer2);
        m_file << "2) " << answer2 << std::endl;

        std::cout << "Enter 3-rd answer: "; std::getline(std::cin, answer3);
        m_file << "3) " << answer3 << std::endl;

        std::cout << "Enter true answer: "; std::cin >> trueAnswer; 
        m_file << trueAnswer << std::endl;
        
    }
    m_file.close(); // destructor@ qneler, asi chhanem qnic
}

void Quiz::answerQuerys(){
    std::cout << "Choose test(1,2): ";
    int choice; std::cin >> choice;

    switch (choice){
        case(1):
            m_currFileName = FILENAME1;
            break;
        case(2):
            m_currFileName = FILENAME2;
            break;
    }

    m_file.open(m_currFileName);

    if (m_file.peek() == std::ifstream::traits_type::eof()){
        std::cout << "This test is empty" << std::endl;
        std::abort();
    }

    std::string userAnswer;

    std::string tmpString;
    size_t countOfReads = 0;

    while (m_file.good()){
        std::getline(m_file, tmpString);
        std::cout << tmpString << std::endl;
        
        
        if (++countOfReads == 4){
            m_file >> tmpString;

            std::cout << "(1,2,3): ";
            std::cin >> userAnswer;
            
            if (userAnswer == tmpString){ //tmpString == AdminAnswer
                std::cout << "true" << std::endl;
            }else{
                std::cout << "false" << std::endl;
            }

            countOfReads = 0;
        }
    }

    m_file.close();

}