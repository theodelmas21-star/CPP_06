/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:45:49 by tdelmas2          #+#    #+#             */
/*   Updated: 2026/06/05 15:29:12 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>

class ScalarConverter
{
  private:
    ScalarConverter(void);
    ScalarConverter(ScalarConverter const &original);
    ScalarConverter &operator=(ScalarConverter const &rhs);
    ~ScalarConverter();
    static int Parsing(std::string toconvert);
    static int isChar(std::string toconvert);
    static int isInt(std::string toconvert);
    static int isFloat(std::string toconvert);
    static int isDouble(std::string toconvert);
    static void printChar(double value);
    static void printInt(double value);
    static void printFloat(double value);
    static void printDouble(double value);
    static void printAll(double value);

  public:
    static void convert(std::string toconvert);
};

#endif