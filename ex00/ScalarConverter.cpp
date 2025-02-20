// ScalarConverter.cpp
#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string literal) {
	char c;
	int i;
	float f;
	//double d;

	if (isChar(literal)) 
	{
		c = literal[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
	} 
	else if (isFloat(literal) || isDouble(literal)) 
	{
		try 
		{
			double d = strtod(literal.c_str(), NULL);
			f = static_cast<float>(strtof(literal.c_str(), NULL));

			if (std::isinf(d))
				d = std::numeric_limits<double>::infinity();
			if (std::isinf(f))
				f = std::numeric_limits<float>::infinity();
			std::cout << "char: " << ((d >= 32 && d <= 126) ? std::string(1, static_cast<char>(d)) : "Non displayable") << std::endl;
			std::cout << "int: " << ((d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min()) ? "impossible" : std::to_string(static_cast<int>(d))) << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << f << "f" << std::endl;
			std::cout << "double: " << d << std::endl;
		} 
		catch (...) 
		{
			std::cout << "Conversion impossible" << std::endl;
		}

	} 
	else if (isInt(literal)) 
	{
		try 
		{
			std::cout << "INT!!!\n";
			i = std::stoi(literal);
			std::cout << "char: " << ((i >= 32 && i <= 126) ? std::string(1, static_cast<char>(i)) : "Non displayable") << std::endl;
			std::cout << "int: " << i << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(i) << std::endl;
		} 
		catch (...) 
		{
			std::cout << "Conversion impossible" << std::endl;
		}
	} 
	else
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: Impossible" << std::endl;
			std::cout << "double: Impossible" << std::endl;
		}
}

bool ScalarConverter::isChar(std::string c) 
{
	if (c.length() == 1 && !isdigit(c[0]) && isprint(c[0]))
		return(true);
	return(false);
}

bool ScalarConverter::isInt(std::string s) 
{
	for (size_t i = 0; i < s.length(); i++) 
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+')) 
			continue;
		if (!isdigit(s[i])) 
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(std::string s) 
{
	int dotCount = 0;
	int fCount = 0;
	if (s.empty() || s == "f") 
		return false;
	if (s == "inf" || s == "-inf" || s == "+inf" || s == "nan")
		return true;
	for (size_t i = 0; i < s.length(); i++) 
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+')) 
			continue;
		if (s[i] == '.') 
			dotCount++;
		else if (s[i] == 'f')
		{
			if (i != s.length() - 1)
				return false;
			fCount++;
		}
		else if (!isdigit(s[i])) 
			return false;
	}
	if (dotCount > 1 && fCount != 1)
		return false;
	return true;
}

bool ScalarConverter::isDouble(std::string s) 
{
	int dotCount = 0;

	if (s.empty()) 
		return false;
	if (s == "inf" || s == "-inf" || s == "+inf" || s == "nan")
		return true;
	for (size_t i = 0; i < s.length(); i++) 
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+')) 
			continue;
		if (s[i] == '.') 
			dotCount++;
		else if (!isdigit(s[i])) 
			return false;
	}
	if (dotCount > 1)
		return false;
	return true;
}
