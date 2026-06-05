/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:45:45 by tdelmas2          #+#    #+#             */
/*   Updated: 2026/06/05 15:36:06 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void){
}

ScalarConverter::ScalarConverter(ScalarConverter const &original){
    (void)original;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs){
    (void)rhs;
    return *this;
}

ScalarConverter::~ScalarConverter(){
}

int ScalarConverter::isChar(std::string toconvert){
    long unsigned int i = 0;

    if (toconvert == "nanf" || toconvert == "inff" || toconvert == "inf" || toconvert == "nan")
        return (0);
    if ((toconvert[i] >= 'a' && toconvert[i] <= 'z') 
            || (toconvert[i] >= 'A' && toconvert[i] <= 'Z'))
    {    
        if (toconvert.length() == 1)
                return (1);
            else
                return (-1);
    }
    return (0);
}

int ScalarConverter::isInt(std::string toconvert){
    long unsigned int i = 0;

    if ((toconvert[i] == '+' || toconvert[i] == '-'))
        i++;
    while (i < toconvert.length())
    {
        if ((toconvert[i] >= '0' && toconvert[i] <= '9'))
            i++;
        else
            return (0);
    }
    return (2);
}

int ScalarConverter::isFloat(std::string toconvert){
    long unsigned int i = 0;
    int count = 0;

    if (toconvert == "nanf" || toconvert == "+inff" || toconvert == "-inff" || toconvert == "inff")
        return (3);
    if ((toconvert[i] == '+' || toconvert[i] == '-'))
        i++;
    while (i < toconvert.length())
    {
        if ((toconvert[i] >= '0' && toconvert[i] <= '9'))
            i++;
        else if (i > 0 && toconvert[i] == '.' && count == 0)
        {
            i++;
            count = 1;
        }
        else if (toconvert[i] == 'f' && i == toconvert.length() - 1 
                    && i > 0 && count == 1 && ((toconvert[i - 1] >= '0' && toconvert[i - 1] <= '9')))
            return (3);
        else
            break;
    }
    return (0);
}

int ScalarConverter::isDouble(std::string toconvert){
    long unsigned int i = 0;
    int count = 0;

    if (toconvert == "nan" || toconvert == "+inf" || toconvert == "-inf" || toconvert == "inf")
        return (4);
    if ((toconvert[i] == '+' || toconvert[i] == '-'))
        i++;
    while (i < toconvert.length())
    {
        if ((toconvert[i] >= '0' && toconvert[i] <= '9'))
            i++;
        else if (i > 0 && toconvert[i] == '.' && count == 0)
        {
            i++;
            count = 1;
        }
        else
            return (0); 
    }
    return (4);
}

int ScalarConverter::Parsing(std::string toconvert){
    int res;
    
    if (toconvert.empty())
    {
        std::cout << "Empty string can't be converted" << "\n";
        return (-1);
    }
    res = ScalarConverter::isChar(toconvert);
    if (res != 0)
        return (res);
    res = ScalarConverter::isInt(toconvert);
    if (res != 0)
        return (res);
    res = ScalarConverter::isFloat(toconvert);
    if (res != 0)
        return (res);
    res = ScalarConverter::isDouble(toconvert);
    if (res != 0)
        return (res);
    return (-1);
}

void ScalarConverter::printChar(double value){
    std::cout << "char: ";
    if (std::isnan(value) || std::isinf(value) || value < 0 || value > 127)
        std::cout << "impossible.\n";
    else if (!std::isprint(static_cast<int>(value)))
        std::cout << "Non Displayable\n";
    else
        std::cout << "" << static_cast<char>(value) << "\n";
}
    
void ScalarConverter::printInt(double value){
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible.\n";
    else
        std::cout << static_cast<int>(value) << "\n";
}
    
void ScalarConverter::printFloat(double value){
    std::cout << "float: ";
    float f = static_cast<float>(value);
    if (f == static_cast<int>(f))
        std::cout << f << ".0f\n";
    else
        std::cout << f << "f\n";
}
    
void ScalarConverter::printDouble(double value){
    std::cout << "double: ";
    if (value == static_cast<int>(value))
        std::cout << value << ".0\n";
    else
        std::cout << value << "\n";
}
    
void ScalarConverter::printAll(double value){
    ScalarConverter::printChar(value);
    ScalarConverter::printInt(value);
    ScalarConverter::printFloat(value);
    ScalarConverter::printDouble(value);
}

void ScalarConverter::convert(std::string toconvert){
    int res;
    double value;

    res = ScalarConverter::Parsing(toconvert);
    if (res == -1)
    {
        std::cout << "To be converted, you have to write a char, int, float or double." << "\n";
        return ;
    }
    if (res != 1)
        value = std::strtod(toconvert.c_str(), NULL);
    else
        value = static_cast<double>(toconvert[0]);
    printAll(value);
}