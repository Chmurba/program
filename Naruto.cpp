#include "Naruto.h"

// Konstruktor
NarutoCharacter::NarutoCharacter(const std::string& name, const std::string& village, int powerLevel)
    : name(name), village(village), powerLevel(powerLevel) {}

// Destruktor
NarutoCharacter::~NarutoCharacter() {}

// Metoda zwracaj�ca nazw� postaci
std::string NarutoCharacter::getName() const {
    return name;
}

// Metoda zwracaj�ca wiosk� postaci
std::string NarutoCharacter::getVillage() const {
    return village;
}

// Metoda zwracaj�ca poziom mocy postaci
int NarutoCharacter::getPowerLevel() const {
    return powerLevel;
}

// Metoda wy�wietlaj�ca informacje o postaci
void NarutoCharacter::displayInfo() const {
    std::cout << "Character: " << name << std::endl;
    std::cout << "Village: " << village << std::endl;
    std::cout << "Power Level: " << powerLevel << std::endl;
}
