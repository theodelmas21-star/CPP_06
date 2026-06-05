/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:45:10 by tdelmas2          #+#    #+#             */
/*   Updated: 2026/06/05 15:12:49 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "It only takes one argument to convert\n";
        return (1);
    }
    ScalarConverter::convert(av[1]);
}