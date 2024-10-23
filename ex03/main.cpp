/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:42:27 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:48 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[94m"

int main(void)
{
	std::cout << BLUE << "----- PDF Test: -----" << std::endl
			  << std::endl;

	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter *me = new Character("me");
	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << GREEN << std::endl
			  << "----- Overfilling Character with Materias: -----" << std::endl
			  << std::endl;

	IMateriaSource *materia_source = new MateriaSource();
	materia_source->learnMateria(new Cure());
	ICharacter *alf = new Character("Alf");
	for (int i = 0; i < 56; i++)
	{
		alf->equip(materia_source->createMateria("cure"));
	}
	delete materia_source;
	delete alf;

	std::cout << YELLOW << std::endl
			  << "----- Copy costructor and assignment operator shinenigans -----" << std::endl
			  << std::endl;

	IMateriaSource *ms = new MateriaSource();
	AMateria *cure = new Cure();
	ms->learnMateria(cure);
	AMateria *temp_materia = ms->createMateria("cure");
	Character *bert = new Character("Bert");
	bert->equip(temp_materia);
	Character *casper = new Character(*bert);
	casper->use(0, *bert);
	casper->use(0, *bert);
	Character *dobby = new Character("Dobby");
	*dobby = *bert;
	dobby->use(0, *bert);
	delete ms;
	delete bert;
	delete casper;
	delete dobby;
}
