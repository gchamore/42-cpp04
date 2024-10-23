/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:52:14 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/17 15:57:17 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class AAnimal : virtual public Brain
{
public:
	AAnimal();
	AAnimal(const std::string &type);
	AAnimal(const AAnimal &other);
	virtual ~AAnimal();

	AAnimal &operator=(const AAnimal &other);

	virtual void makeSound() const = 0;
	std::string getType() const;
	virtual Brain* getBrain() const = 0;
protected:
	std::string _type;
};

#endif