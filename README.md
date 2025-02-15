# 🎭 C++ - Module 04

## 📝 Présentation

Le module **C++ 04** approfondit le concept de **polymorphisme**, en introduisant les **classes abstraites** et les **interfaces**.  
L'objectif est de comprendre comment structurer un programme avec une hiérarchie d'objets, tout en respectant les principes de l'**héritage** et de l'**encapsulation**.

---

## 🛠️ Fonctionnalités

- **Exercice 00 : Polymorphisme**
  - Création d’une classe de base `Animal` avec un attribut `std::string type`.
  - Définition des classes `Dog` et `Cat`, héritant de `Animal`, et redéfinition de `makeSound()`.
  - Introduction d’un `WrongAnimal` et d’un `WrongCat` pour tester le **polymorphisme**.

- **Exercice 01 : Je ne veux pas brûler le monde**
  - Ajout d’une classe `Brain` avec un tableau de **100 idées**.
  - Association de `Brain` aux classes `Dog` et `Cat` (composition).
  - Implémentation d’une **copie profonde** pour éviter les **fuites mémoire**.

- **Exercice 02 : Classe abstraite**
  - Transformation de `Animal` en **classe abstraite** (méthode virtuelle pure `makeSound()`).
  - Interdiction d’instancier directement `Animal`.
  - Vérification du bon fonctionnement du programme avec le **même comportement**.

- **Exercice 03 : Interface & recap**
  - Implémentation d’une interface **`IMateriaSource`**.
  - Création de **materias** (`Ice`, `Cure`), utilisables par des `Character`.
  - Gestion d’un **inventaire de 4 materias** par personnage.
  - Ajout d’un système de **clonage de materias**.

---

## 📌 Technologies Utilisées

- **C++ 98**  
- **Polymorphisme dynamique** (`virtual`)  
- **Classes abstraites et interfaces**  
- **Gestion de la mémoire dynamique (`new` / `delete`)**  
- **Héritage et composition**  

---

## 🏗️ Structure du Projet

📂 ex00  
┣ 📜 Animal.cpp  
┣ 📜 Animal.hpp  
┣ 📜 Cat.cpp  
┣ 📜 Cat.hpp  
┣ 📜 Dog.cpp  
┣ 📜 Dog.hpp  
┣ 📜 WrongAnimal.cpp  
┣ 📜 WrongAnimal.hpp  
┣ 📜 WrongCat.cpp  
┣ 📜 WrongCat.hpp  
┣ 📜 Makefile  
┗ 📜 main.cpp  

📂 ex01  
┣ 📜 Animal.cpp  
┣ 📜 Animal.hpp  
┣ 📜 Brain.cpp  
┣ 📜 Brain.hpp  
┣ 📜 Cat.cpp  
┣ 📜 Cat.hpp  
┣ 📜 Dog.cpp  
┣ 📜 Dog.hpp  
┣ 📜 WrongAnimal.cpp  
┣ 📜 WrongAnimal.hpp  
┣ 📜 WrongCat.cpp  
┣ 📜 WrongCat.hpp  
┣ 📜 Makefile  
┗ 📜 main.cpp  

📂 ex02  
┣ 📜 Animal.cpp  
┣ 📜 Animal.hpp  
┣ 📜 Brain.cpp  
┣ 📜 Brain.hpp  
┣ 📜 Cat.cpp  
┣ 📜 Cat.hpp  
┣ 📜 Dog.cpp  
┣ 📜 Dog.hpp  
┣ 📜 WrongAnimal.cpp  
┣ 📜 WrongAnimal.hpp  
┣ 📜 WrongCat.cpp  
┣ 📜 WrongCat.hpp  
┣ 📜 Makefile  
┗ 📜 main.cpp  

📂 ex03  
┣ 📜 AMateria.cpp  
┣ 📜 AMateria.hpp  
┣ 📜 Character.cpp  
┣ 📜 Character.hpp  
┣ 📜 Cure.cpp  
┣ 📜 Cure.hpp  
┣ 📜 Ice.cpp  
┣ 📜 Ice.hpp  
┣ 📜 IMateriaSource.hpp  
┣ 📜 MateriaSource.cpp  
┣ 📜 MateriaSource.hpp  
┣ 📜 Makefile  
┗ 📜 main.cpp  


---

## 🔥 Difficultés Rencontrées

- **Compréhension du polymorphisme** : Différence entre **virtual** et non-virtual.  
- **Gestion correcte des destructeurs** : Éviter les **fuites mémoire** avec des **destructeurs virtuels**.  
- **Implémentation d’une copie profonde** : Assurer que `Brain` est bien **dupliqué** et non simplement copié par adresse.  
- **Respect des classes abstraites** : Interdiction d’instancier `Animal` après l’ajout d’une méthode virtuelle pure.  
- **Gestion dynamique des objets (`new` / `delete`)** : Suivi des allocations et désallocations pour éviter les **memory leaks**.  
- **Utilisation d’une interface (`IMateriaSource`)** : Comprendre son rôle et son interaction avec d’autres classes.  

---

## 🏗️ Mise en place

1. **Cloner le dépôt** :  
  ```bash
  git clone https://github.com/ton-repo/cpp04.git
  cd cpp04
  ```

2. **Compiler et exécuter chaque exercice** :

**Exercice 00** :   
   ```bash
   cd ex00
   make
   ./polymorphism
   make fclean
   ```

**Exercice 01** :  
  ```bash
   cd ex01
   make
   ./brain
   make fclean
   ```

**Exercice 02** :  
   ```bash
   cd ex02
   make
   ./abstract
   make fclean
   ```

**Exercice 03** :  
   ```bash
   cd ex03
   make
   ./materia
   make fclean
   ```

---

## 👨‍💻 Équipe  

👤 Grégoire Chamorel (Gchamore)  

---

## 📜 Projet réalisé dans le cadre du cursus 42.  

Tu peux bien sûr modifier ce README selon tes besoins, ajouter plus de détails sur ton approche et des instructions d’installation précises. 🚀  
