/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:06:43 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/22 16:16:06 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>
#include <sstream>

class Brain
{
public:
	Brain();
	Brain(const std::string &idea);
	Brain(const Brain &other);
	virtual ~Brain();

	Brain &operator=(const Brain &other);
	std::string getIdea(int index) const;
	
protected:
	std::string _ideas[100];
};

#endif