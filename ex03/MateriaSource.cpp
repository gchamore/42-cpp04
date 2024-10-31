/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:35:05 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/31 11:07:39 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		this->memory_[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
	{
		if (copy.memory_[i])
		{
			this->memory_[i] = copy.memory_[i]->clone();
			this->memory_[i]->setMateriaSource(this);
		}
		else
			this->memory_[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->memory_[i])
			delete this->memory_[i];
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (this->memory_[i] != NULL)
                delete this->memory_[i];
            if (other.memory_[i] != NULL)
                this->memory_[i] = other.memory_[i]->clone();
            else
                this->memory_[i] = NULL;
        }
    }
    return *this;
}


AMateria *MateriaSource::getMemory(int idx) const
{
	if (idx < 0 || idx > 3)
		return NULL;
	return this->memory_[idx];
}

void MateriaSource::setMemory(int idx, AMateria *materia)
{
	if (idx < 0 || idx > 3)
		return;
	this->memory_[idx] = materia;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->memory_[i] == NULL)
		{
			this->memory_[i] = materia;
			materia->setMateriaSource(this);
			std::cout << "Materia source learned " << materia->getType() << "!" << std::endl;
			return;
		}
	}
	std::cout << "Couldn't learn " << materia->getType() << ", because materia source is full." << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 3; i >= 0; i--)
	{
		if (this->memory_[i] && this->memory_[i]->getType() == type)
		{
			std::cout << "Materia source creates " << type << std::endl;
			return this->memory_[i]->clone();
		}
	}
	std::cout << "Materia source cannot create " << type << ". Not learned." << std::endl;
	return NULL;
}