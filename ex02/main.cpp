/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:42:27 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/22 16:37:59 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// const AAnimal* meta = new AAnimal();
    const int num_animals = 4;
    const AAnimal* animalArray[num_animals];

    for (int i = 0; i < num_animals / 2; i++)
    {
        animalArray[i] = new Dog();
    }
    for (int i = num_animals / 2; i < num_animals; i++)
    {
        animalArray[i] = new Cat();
    }

    std::cout << "\nTesting AAnimal sounds and types:\n" << std::endl;
    for (int i = 0; i < num_animals; i++)
    {
        std::cout << "AAnimal type: " << animalArray[i]->getType() << std::endl;
        animalArray[i]->makeSound();
    }

    std::cout << "\nDisplaying ideas from Dogs and Cats' brains:" << std::endl;
    for (int i = 0; i < num_animals; i++)
    {
        const Brain* brain = animalArray[i]->getBrain();
        if (brain)
        {
            std::cout << "\nBrain ideas for " << animalArray[i]->getType() << ":" << std::endl;
            for (int j = 0; j < 5; j++)
            {
                std::cout << "Idea " << j << ": " << brain->getIdea(j) << std::endl;
            }
        }
    }

    std::cout << "\nDeleting AAnimals:\n" << std::endl;
    for (int i = 0; i < num_animals; i++)
    {
        delete animalArray[i];
    }
	// delete meta;
    return 0;
}


