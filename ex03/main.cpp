/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:42:27 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/31 11:11:34 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

// #define GREEN "\033[32m"
// #define YELLOW "\033[33m"
// #define BLUE "\033[94m"

// int main(void)
// {
// 	std::cout << BLUE << "----- Test: -----" << std::endl << std::endl;

// 	IMateriaSource *src = new MateriaSource();
// 	src->learnMateria(new Ice());
// 	src->learnMateria(new Cure());
// 	ICharacter *me = new Character("me");
// 	AMateria *tmp;
// 	tmp = src->createMateria("ice");
// 	me->equip(tmp);
// 	tmp = src->createMateria("cure");
// 	me->equip(tmp);
// 	ICharacter *Franky = new Character("Franky");
// 	me->use(0, *Franky);
// 	me->use(1, *Franky);
// 	delete Franky;
// 	delete me;
// 	delete src;

// 	std::cout << GREEN << std::endl << "----- Overfilling Character with Materias: -----" << std::endl << std::endl;

// 	IMateriaSource *materia_source = new MateriaSource();
// 	materia_source->learnMateria(new Cure());
// 	ICharacter *Didier = new Character("Didier");
// 	for (int i = 0; i < 56; i++)
// 	{
// 		AMateria *materia = materia_source->createMateria("cure");
// 		Didier->equip(materia); // Plus besoin de gérer explicitement l’échec, il est géré dans `equip`.
// 	}
// 	delete materia_source;
// 	delete Didier;

// 	std::cout << YELLOW << std::endl << "----- Verif if Deep Copy with Copy constructor and assignment operator -----" << std::endl << std::endl;

// 	IMateriaSource *ms = new MateriaSource();
// 	AMateria *cure = new Cure();
// 	ms->learnMateria(cure);
// 	AMateria *temp_materia = ms->createMateria("cure");
// 	Character *Patoche = new Character("Patoche");
// 	Patoche->equip(temp_materia);
// 	Character *casper = new Character(*Patoche);
// 	casper->use(0, *Patoche);
// 	casper->use(0, *Patoche);
// 	Character *dobby = new Character("Dobby");
// 	*dobby = *Patoche;
// 	dobby->use(0, *Patoche);
// 	delete ms;
// 	delete Patoche;
// 	delete casper;
// 	delete dobby;
// }

int main()
{
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
	return 0;
}