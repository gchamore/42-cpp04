/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:35:07 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/23 15:39:59 by gchamore         ###   ########.fr       */
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

	MateriaSource &operator=(MateriaSource other);
	void swap(MateriaSource &first, MateriaSource &second);

	AMateria *getMemory(int idx) const;
	void setMemory(int idx, AMateria *materia);

	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(std::string const &type);

private:
	AMateria *memory_[4];
};

#endif