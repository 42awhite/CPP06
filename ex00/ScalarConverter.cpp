// ScalarConverter.cpp
#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    char c;
    int i;
    float f;
    double d;

    if (isChar(literal)) {
        c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    } else if (isInt(literal)) {
        try {
            i = std::stoi(literal);
            std::cout << "char: " << ((i >= 32 && i <= 126) ? std::string(1, static_cast<char>(i)) : "Non displayable") << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
        } catch (...) {
            std::cout << "Conversion impossible" << std::endl;
        }
    } else if (isFloat(literal) || isDouble(literal)) {
        try {
            f = std::stof(literal);
            d = std::stod(literal);
            std::cout << "char: " << ((d >= 32 && d <= 126) ? std::string(1, static_cast<char>(d)) : "Non displayable") << std::endl;
            std::cout << "int: " << ((d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) ? "impossible" : std::to_string(static_cast<int>(d))) << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        } catch (...) {
            std::cout << "Conversion impossible" << std::endl;
        }
    } else {
        std::cout << "Conversion impossible" << std::endl;
    }
}

bool ScalarConverter::isChar(const std::string &s) {
    return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

bool ScalarConverter::isInt(const std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        if (i == 0 && (s[i] == '-' || s[i] == '+')) continue;
        if (!isdigit(s[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string &s) {
    return s.find('f') != std::string::npos;
}

bool ScalarConverter::isDouble(const std::string &s) {
    return s.find('.') != std::string::npos;
}
