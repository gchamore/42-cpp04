/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:40:48 by gchamore          #+#    #+#             */
/*   Updated: 2024/09/30 14:53:07 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->_type = "ice";
	this->_mage = NULL;
	this->_materia_source = NULL;
}

Ice::Ice(const Ice &other)
{
	other.getType();
	this->_type = "ice";
	this->_mage = other._mage;
	this->_materia_source = other._materia_source;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice other)
{
	std::cout << "Assigning a ice to another ice doesn't make sense." << std::endl;
	(void)other;
	return *this;
}

AMateria *Ice::clone() const
{
	AMateria *temp = new Ice(*this);
	temp->setmage(NULL);
	temp->setMateriaSource(NULL);
	return temp;
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}