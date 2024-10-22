/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gchamore <gchamore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:42:27 by gchamore          #+#    #+#             */
/*   Updated: 2024/10/22 14:36:43 by gchamore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "Testing Animal sounds and types:\n" << std::endl;
    
    // Création de Dog, Cat, et WrongCat via des pointeurs sur Animal et WrongAnimal
    const Animal* meta = new Animal();
	const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* h = new WrongCat();

	std::cout << std::endl;

    // Afficher les types
	std::cout << "Animal type (Animal): " << meta->getType() << std::endl;
    std::cout << "Animal type (Dog): " << j->getType() << std::endl;
    std::cout << "Animal type (Cat): " << i->getType() << std::endl;
	std::cout << "WrongAnimal type (WrongCat): " << h->getType() << std::endl;

    // Afficher les sons
    std::cout << "\nSounds of animals:\n" << std::endl;
	meta->makeSound(); // Animal sound
    j->makeSound();  // Woof!
    i->makeSound();  // Meow!
    h->makeSound();  // WrongAnimal sound (WrongCat devrait faire le son de WrongAnimal)

    std::cout << "\nTest completed. Deleting objects...\n" << std::endl;

    // Libération de la mémoire pour appeler les destructeurs
	delete meta;
    delete j;
    delete i;
    delete h;

    std::cout << "\nFurther testing with polymorphism:\n" << std::endl;

    // Test de polymorphisme avec tableau de pointeurs
    const Animal* animalArray[4];
    animalArray[0] = new Dog();
    animalArray[1] = new Cat();
    animalArray[2] = new Dog();
    animalArray[3] = new Cat();

	std::cout << std::endl;

    // Boucle pour afficher les types et les sons
    for (int k = 0; k < 4; ++k)
    {
        std::cout << "Animal type: " << animalArray[k]->getType() << std::endl;
        animalArray[k]->makeSound();
    }

    std::cout << "\nDeleting the animals in array:\n" << std::endl;
    for (int k = 0; k < 4; ++k)
    {
        delete animalArray[k];  // Appelle les destructeurs de Dog ou Cat
    }

    return 0;
}

