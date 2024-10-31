/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:35:07 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/31 11:07:20 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &copy);

	virtual ~MateriaSource();

	MateriaSource &operator=(const MateriaSource &other);

	AMateria *getMemory(int idx) const;
	void setMemory(int idx, AMateria *materia);

	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(std::string const &type);

private:
	AMateria *memory_[4];
};

#endif