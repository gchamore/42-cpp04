/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:52:14 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/17 15:57:17 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include <iostream>
#include "Character.hpp"
#include "MateriaSource.hpp"

class Character;
class ICharacter;
class MateriaSource;
class IMateriaSource;

class AMateria
{
public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &copy);

	virtual ~AMateria();

	AMateria &operator=(const AMateria &other);

	std::string const &getType() const;
	Character *getmage() const;
	void setmage(Character *new_mage);
	MateriaSource *getMateriaSource() const;
	void setMateriaSource(MateriaSource *new_materia_source);

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target) = 0;

protected:
	std::string _type;
	Character *_mage;
	MateriaSource *_materia_source;
	bool is_on_floor;
};

#endif