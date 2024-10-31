/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:02:44 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/31 11:09:23 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character();
	Character(std::string name);
	Character(const Character &copy);

	virtual ~Character();

	Character &operator=(const Character &other);

	std::string const &getName() const;
	void setName(std::string name);
	AMateria *getInventory(int idx) const;
	void setInventory(int idx, AMateria *materia);

	virtual void equip(AMateria *m);
	virtual void equip_from_floor(int idx);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter &target);

	static AMateria *floor_[50];

private:
	std::string _name;
	AMateria *_inventory[4];
	static int _n_characters;
};

#endif