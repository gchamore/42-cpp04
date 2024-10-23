/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:06:45 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/22 16:16:03 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

std::string intToString(int number)
{
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

Brain::Brain()
{
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const std::string& idea)
{
	std::cout << "Brain with idea constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
        _ideas[i] = idea + " " + intToString(i);
    }
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain Copy constructor called" << std::endl;
	for (int i = 0; i < 100; ++i)
	{
		_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain Destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
		{
			_ideas[i] = other._ideas[i];
		}
	}
	std::cout << "Assignment operator called" << std::endl;
	return *this;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
    {
        return _ideas[index];
    }
    return "Invalid idea index";
}