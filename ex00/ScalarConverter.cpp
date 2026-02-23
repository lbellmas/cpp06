#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}
ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter& copy)
{
    (void)copy;
    return (*this);
}

static int isChar(const std::string& literal)
{
    if (literal.length() != 3 || literal[0] != '\'' || literal[2] != '\'')
        return (0);
    char c = literal[1];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
    return (1);
}

static double isDouble(const std::string& literal)
{
    if (literal == "nanf" || literal == "nan")
        return (std::numeric_limits<float>::quiet_NaN());
    if (literal == "+inff" || literal == "+inf")
        return (std::numeric_limits<float>::infinity());
    if (literal == "-inff" || literal == "-inf")
        return (-std::numeric_limits<float>::infinity());
    return (std::strtod(literal.c_str(), NULL));
}

static void    charConvert(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (d < 32 || d > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

static void   intConvert(double d)
{
    if (std::isnan(d) || std::isinf(d) || d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void    floatConvert(double d)
{
    if (std::isnan(d))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(d) && d > 0)
        std::cout << "float: +inff" << std::endl;
    else if (std::isinf(d) && d < 0)
        std::cout << "float: -inff" << std::endl;
    else if (d == 0)
        std::cout << "float: 0f" << std::endl;
    else if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
}

void    ScalarConverter::convert(const std::string& literal)
{
    double d;

    if (isChar(literal))
        return ;
    d = isDouble(literal);
    if (d == 0 && literal[1] != '\0')
    {
        std::cout << "no valid literal" << std::endl;
        return ;
    }
    charConvert(d);
    intConvert(d);
    floatConvert(d );
    std::cout << "double: " << d << std::endl; 
}