/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:02:41 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:24 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

int Character::_n_characters = 0;
AMateria *Character::floor_[50] = {NULL};

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	_n_characters++;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	_name = "nameless hero";
}

Character::Character(std::string name)
{
	std::cout << "Character name constructor called" << std::endl;
	_n_characters++;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	this->_name = name;
}

Character::Character(const Character &copy)
{
	std::cout << "Character copy construtor called" << std::endl;
	_n_characters++;
	this->_name = copy._name;
	for (int i = 0; i < 4; i++)
	{
		if (copy._inventory[i])
		{
			this->_inventory[i] = copy._inventory[i]->clone();
			this->_inventory[i]->setmage(this);
		}
		else
		{
			this->_inventory[i] = NULL;
		}
	}
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	_n_characters--;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}

	// If no characters are left, delete items on the floor
	if (_n_characters == 0)
	{
		std::cout << "All characters are gone. Items on the floor disappear." << std::endl;
		for (int i = 0; i < 50; i++)
		{
			if (floor_[i])
			{
				delete floor_[i];
				floor_[i] = NULL;
			}
		}
	}
}

void Character::swap(Character &first, Character &second)
{
	std::swap(first._name, second._name);
	std::swap(first._inventory, second._inventory);
}

Character &Character::operator=(const Character &other)
{
	std::cout << "Character copy assignment operator called" << std::endl;
	Character tmp = Character(other);
	Character::swap(*this, tmp);
	return *this;
}

std::string const &Character::getName() const { return this->_name; }

void Character::setName(std::string name) { this->_name = name; }

AMateria *Character::getInventory(int idx) const
{
	if (idx < 0 || idx > 3)
		return NULL;
	return this->_inventory[idx];
}

void Character::setInventory(int idx, AMateria *materia)
{
	if (idx < 0 || idx > 3)
		return;
	this->_inventory[idx] = materia;
}

void Character::equip(AMateria *m)
{
	if (!m)
	{
		std::cout << "Materia doesn't exist!" << std::endl;
		return;
	}
	if (m->getmage())
	{
		std::cout << m->getType() << " is still equipped to " << m->getmage()->getName() << ". Can't equip it to another slot!" << std::endl;
		return;
	}
	if (m->getMateriaSource())
	{
		std::cout << m->getType() << " is already equipped to a materia source. Can't equip it to "
									 "another slot!"
				  << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			m->setmage(this);
			std::cout << this->getName() << " equipped " << m->getType() << ". (slot " << i << ")" << std::endl;
			return;
		}
	}
	for (int i = 0; i < 50; i++)
	{
		if (Character::floor_[i] == NULL)
		{
			floor_[i] = m;
			floor_[i]->setmage(NULL);
			std::cout << this->_name << "'s inventory is full. Can't equip " << m->getType() << ". It falls onto the floor! (location: " << i << ")" << std::endl;
			return;
		}
	}
	std::cout << this->_name << "'s inventory is full. The materia falls onto the ground and "
								"shatters, as the floor is already full of other materias!"
			  << std::endl;
	delete m;
}

void Character::equip_from_floor(int idx)
{
	if (idx < 0 || idx > 49)
	{
		std::cout << "Invalid floor index!" << std::endl;
		return;
	}
	if (this->floor_[idx] == NULL)
	{
		std::cout << "There is nothing at this spot on the floor to equip!" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = this->floor_[idx];
			this->_inventory[i]->setmage(this);
			this->floor_[idx] = NULL;
			std::cout << this->getName() << " equipped " << this->_inventory[i]->getType() << ". (slot " << i << ")" << std::endl;
			return;
		}
	}
	std::cout << this->_name << "'s inventory is full. Can't equip " << this->floor_[idx]->getType() << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory index!" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Inventory slot already empty!" << std::endl;
		return;
	}
	int i;
	for (i = 0; i < 50; i++)
	{
		if (Character::floor_[i] == NULL)
		{
			floor_[i] = this->_inventory[i];
			floor_[i]->setmage(NULL);
			std::cout << "Materia is unequipped and falls on the ground! (location: " << i << ")" << std::endl;
			break;
		}
	}
	if (i == 50)
	{
		std::cout << "Too many materias on the floor. The hero can't move their "
					 "arms to unequip the item!"
				  << std::endl;
		return;
	}
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid inventory index!" << std::endl;
		return;
	}
	if (this->_inventory[idx] == NULL)
	{
		std::cout << "Slot " << idx << " is empty!" << std::endl;
		return;
	}
	std::cout << _name << ": ";
	this->_inventory[idx]->use(target);
	delete this->_inventory[idx];
	this->_inventory[idx] = NULL;
}