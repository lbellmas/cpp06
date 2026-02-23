#include <iostream>

class ScalarConverter
{
    public:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &other);
        void convert(const std::string& literal);
};