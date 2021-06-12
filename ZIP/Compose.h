#ifndef COMP_H
#define COMP_h

#include <string>
#include <fstream>
#include <string>

class Compose {
public:
    Compose() = default;
    Compose(const std::string&);
    ~Compose();

    void decompose(const std::string&);
    void compose(const std::string&);
private:
    std::string m_inputString;
    std::fstream m_file;
};

#endif //COMP_h