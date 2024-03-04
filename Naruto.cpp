#include "Naruto.h"

// Konstruktor
NarutoCharacter::NarutoCharacter(const std::string& name, const std::string& village, int powerLevel)
    : name(name), village(village), powerLevel(powerLevel) {}

// Destruktor
NarutoCharacter::~NarutoCharacter() {}

// Metoda zwracaj¹ca nazwê postaci
std::string NarutoCharacter::getName() const {
    return name;
}

// Metoda zwracaj¹ca wioskê postaci
std::string NarutoCharacter::getVillage() const {
    return village;
}

// Metoda zwracaj¹ca poziom mocy postaci
int NarutoCharacter::getPowerLevel() const {
    return powerLevel;
}

// Metoda wyœwietlaj¹ca informacje o postaci
void NarutoCharacter::displayInfo() const {
    std::cout << "Character: " << name << std::endl;
    std::cout << "Village: " << village << std::endl;
    std::cout << "Power Level: " << powerLevel << std::endl;
}
