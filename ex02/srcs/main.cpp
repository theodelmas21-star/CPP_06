/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelmas2 <tdelmas2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 09:45:10 by tdelmas2          #+#    #+#             */
/*   Updated: 2026/06/08 10:53:22 by tdelmas2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base *generate(void)
{
    int random = rand() % 3;
    switch (random)
    {
    case 0:
        std::cout << "[Générateur] Création d'une instance de A" << std::endl;
        return new A();
    case 1:
        std::cout << "[Générateur] Création d'une instance de B" << std::endl;
        return new B();
    case 2:
        std::cout << "[Générateur] Création d'une instance de C" << std::endl;
        return new C();
        std::cout << "[Générateur] Erreur inattendue" << std::endl;

        return NULL;
    }
    return NULL;
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
    {
        std::cout << "A" << std::endl;
    }
    else if (dynamic_cast<B *>(p) != NULL)
    {
        std::cout << "B" << std::endl;
    }
    else if (dynamic_cast<C *>(p) != NULL)
    {
        std::cout << "C" << std::endl;
    }
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        (void)a;
        return;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        (void)b;
        return;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        (void)c;
        return;
    }
    catch (const std::exception &e)
    {
        (void)e;
    }
}

int main(void)
{
    srand(time(NULL));
    Base *test = generate();

    identify(*test);
    identify(test);

    delete test;
    return 0;
}