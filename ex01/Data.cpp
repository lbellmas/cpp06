#include "Data.hpp"

Data::Data()
{
    s = "";
}
Data::Data(std::string str)
{
    s = str;
}

Data::Data(const Data& other)
{
    s = other.s;
}

Data::~Data()
{}

Data &Data::operator=(const Data& copy)
{
    if (this != &copy)
        s = copy.s;
    return (*this);
}