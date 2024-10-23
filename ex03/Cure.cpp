/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:40:48 by gchamore          #+#    #+#             */
/*   Updated: 2024/09/30 14:53:07 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
	this->_mage = NULL;
	this->_materia_source = NULL;
}

Cure::Cure(const Cure &other)
{
	this->_type = "cure";
	this->_mage = other._mage;
	this->_materia_source = other._materia_source;
}

Cure::~Cure()
{
}

Cure &Cure::operator=(Cure other)
{
	std::cout << "Assigning a cure to another cure doesn't make sense." << std::endl;
	(void)other;
	return *this;
}

AMateria *Cure::clone() const
{
	AMateria *temp = new Cure(*this);
	temp->setmage(NULL);
	temp->setMateriaSource(NULL);
	return temp;
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}