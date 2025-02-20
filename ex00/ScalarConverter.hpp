#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>

class ScalarConverter {
public:
    static void convert(const std::string &literal);

private:
    ScalarConverter(); // Constructor privado para evitar instanciación
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);

    static bool isInt(const std::string &s);
    static bool isFloat(const std::string &s);
    static bool isDouble(const std::string &s);
    static bool isChar(const std::string &s);
};

#endif 
