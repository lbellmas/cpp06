#include <iostream>

class Data
{
    private:
        std::string s;
    public:
        Data();
        Data(std::string str);
        Data(const Data& other);
        ~Data();
        Data &operator=(const Data& copy);
};