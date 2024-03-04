#ifndef NARUTO_CHARACTER
#define NARUTO_CHARACTER

#include <string>
#include <iostream>

/**
 * @brief Klasa reprezentuj�ca posta� z mangi "Naruto".
 */
class NarutoCharacter {
private:
    std::string name;
    std::string village;
    int powerLevel;

public:
    /**
     * @brief Konstruktor tworz�cy posta� z podanymi danymi.
     * @param name Nazwa postaci.
     * @param village Wioska, do kt�rej nale�y posta�.
     * @param powerLevel Poziom mocy postaci.
     */
    NarutoCharacter(const std::string& name, const std::string& village, int powerLevel);

    /**
     * @brief Destruktor.
     */
    ~NarutoCharacter();

    /**
     * @brief Metoda zwracaj�ca nazw� postaci.
     * @return Nazwa postaci.
     */
    std::string getName() const;

    /**
     * @brief Metoda zwracaj�ca wiosk�, do kt�rej nale�y posta�.
     * @return Wioska postaci.
     */
    std::string getVillage() const;

    /**
     * @brief Metoda zwracaj�ca poziom mocy postaci.
     * @return Poziom mocy postaci.
     */
    int getPowerLevel() const;

    /**
     * @brief Metoda wy�wietlaj�ca informacje o postaci na ekranie.
     */
    void displayInfo() const;
};

#endif // NARUTO_CHARACTER
