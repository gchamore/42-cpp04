/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:40:48 by gchamore          #+#    #+#             */
/*   Updated: 2024/09/30 14:53:07 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("")
{
	this->_mage = NULL;
	this->_materia_source = NULL;
	this->is_on_floor = false;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	this->_mage = NULL;
	this->_materia_source = NULL;
	this->is_on_floor = false;
}

AMateria::AMateria(const AMateria &copy) : _type(copy._type)
{
	this->_mage = NULL;
	this->_materia_source = NULL;
	this->is_on_floor = false;
}

AMateria::~AMateria()
{	
}

AMateria &AMateria::operator=(const AMateria &other)
{
	this->_type = other._type;
	return *this;
}

std::string const &AMateria::getType() const
{
	return this->_type;
}

Character *AMateria::getmage() const
{
	return this->_mage;
}

void AMateria::setmage(Character *new_mage)
{
	this->_mage = new_mage;
}

MateriaSource *AMateria::getMateriaSource() const
{
	return this->_materia_source;
}

void AMateria::setMateriaSource(MateriaSource *new_materia_source)
{
	this->_materia_source = new_materia_source;
}