#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
public:
    static void convert(std::string literal);

private:
    ScalarConverter(); // Constructor privado para evitar instanciación
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);

    static bool isInt(std::string s);
    static bool isFloat(std::string s);
    static bool isDouble(std::string s);
    static bool isChar(std::string s);
};

#endif 
