#ifndef NARUTO_CHARACTER
#define NARUTO_CHARACTER

#include <string>
#include <iostream>

/**
 * @brief Klasa reprezentuj¹ca postaæ z mangi "Naruto".
 */
class NarutoCharacter {
private:
    std::string name;
    std::string village;
    int powerLevel;

public:
    /**
     * @brief Konstruktor tworz¹cy postaæ z podanymi danymi.
     * @param name Nazwa postaci.
     * @param village Wioska, do której nale¿y postaæ.
     * @param powerLevel Poziom mocy postaci.
     */
    NarutoCharacter(const std::string& name, const std::string& village, int powerLevel);

    /**
     * @brief Destruktor.
     */
    ~NarutoCharacter();

    /**
     * @brief Metoda zwracaj¹ca nazwê postaci.
     * @return Nazwa postaci.
     */
    std::string getName() const;

    /**
     * @brief Metoda zwracaj¹ca wioskê, do której nale¿y postaæ.
     * @return Wioska postaci.
     */
    std::string getVillage() const;

    /**
     * @brief Metoda zwracaj¹ca poziom mocy postaci.
     * @return Poziom mocy postaci.
     */
    int getPowerLevel() const;

    /**
     * @brief Metoda wyœwietlaj¹ca informacje o postaci na ekranie.
     */
    void displayInfo() const;
};

#endif // NARUTO_CHARACTER
