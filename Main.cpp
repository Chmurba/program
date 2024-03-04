#include "Naruto.h"

int main() {
    // Tworzenie postaci
    NarutoCharacter naruto("Naruto Uzumaki", "Konohagakure", 100);
    NarutoCharacter sasuke("Sasuke Uchiha", "Konohagakure", 95);

    // Wyœwietlanie informacji o postaciach
    naruto.displayInfo();
    std::cout << std::endl;
    sasuke.displayInfo();

    return 0;
}
