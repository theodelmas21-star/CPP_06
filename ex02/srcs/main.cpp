/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:45:10 by tdelmas2          #+#    #+#             */
/*   Updated: 2026/06/08 09:42:28 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include "../includes/Serializer.hpp"

int main(void)
{
    Data monObjet;
    monObjet.num = 42;
    monObjet.name = "Lala";

    Data *ptrOrigine = &monObjet;

    uintptr_t rawBits = Serializer::serialize(ptrOrigine);

    Data *ptrDestination = Serializer::deserialize(rawBits);

    std::cout << "Adresse d'origine      : " << ptrOrigine << std::endl;
    std::cout << "Valeur brute (uintptr) : " << rawBits << std::endl;
    std::cout << "Adresse de destination : " << ptrDestination << std::endl;

    if (ptrOrigine == ptrDestination)
    {
        std::cout << "SUCCÈS : Les pointeurs sont identiques !" << std::endl;
        std::cout << "Données intactes : " << ptrDestination->name << " (NUM: " << ptrDestination->num << ")"
                  << std::endl;
    }
    else
    {
        std::cout << "ÉCHEC : Les pointeurs diffèrent." << std::endl;
    }

    return 0;
}