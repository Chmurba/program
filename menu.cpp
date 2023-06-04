#include <iostream>
#include <fstream>
#include <ctime>
#include "ArduinoJson-v6.21.2.h"

using namespace std;

void saveResult(const string& playerName, int attempts) {
    // Otwórz plik JSON do odczytu
    ifstream file("wyniki.json");
    DynamicJsonDocument doc(1024);

    // Sprawdź, czy plik istnieje i sparsuj jego zawartość
    if (file) {
        DeserializationError error = deserializeJson(doc, file);
        file.close();

        // Obsłuż błędy parsowania
        if (error) {
            cout << "Nie udalo sie sparsowac pliku JSON." << endl;
            return;
        }
    }

    // Utwórz obiekt JSON dla wyniku aktualnego gracza
    JsonObject result = doc.createNestedObject();
    result["Gracz"] = playerName;
    result["Liczba_prob"] = attempts;

    // Otwórz plik JSON do zapisu
    ofstream outputFile("wyniki.json");
    if (outputFile) {
        // Serializuj dokument JSON i zapisz go do pliku
        serializeJson(doc, outputFile);
        outputFile.close();
        cout << "Wynik zapisany." << endl;
    }
    else {
        cout << "Nie udalo się zapisac wyniku do pliku." << endl;
    }
}

void displayResults() {
    ifstream file("wyniki.json");
    DynamicJsonDocument doc(1024);

    if (file) {
        DeserializationError error = deserializeJson(doc, file);
        file.close();

        if (error) {
            cout << "Nie udalo się sparsowac pliku JSON." << endl;
            return;
        }
    }
    else {
        cout << "Brak wynikow do wyswietlenia." << endl;
        return;
    }

    JsonArray results = doc.as<JsonArray>();

    cout << "Tabela wynikow:" << endl;
    cout << "-------------------------" << endl;
    cout << "Gracz\t\tLiczba prob" << endl;
    cout << "-------------------------" << endl;

    for (const auto& result : results) {
        cout << result["Gracz"].as<string>() << "\t\t" << result["Liczba_prob"].as<int>() << endl;
    }

    cout << "-------------------------" << endl;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));
    int wylosowanaLiczba = rand() % 100 + 1;
    int zgadywanaLiczba;
    int licznikProb = 0;
    string nazwaGracza;

    cout << "Witaj w grze! Podaj swoje imie: ";
    cin >> nazwaGracza;

    cout << "Witaj, " << nazwaGracza << "! Zgadnij liczbę od 1 do 100." << endl;

    bool wyjscie = false;
    do {
        cout << "Menu:" << endl;
        cout << "1. Zgadywanie liczby" << endl;
        cout << "2. Wyswietl tabele wynikow" << endl;
        cout << "3. Wyjscie z gry" << endl;
        cout << "Wybierz opcje: ";

        int opcja;
        cin >> opcja;

        switch (opcja) {
        case 1: {
            do {
                cout << "Podaj liczbe: ";
                cin >> zgadywanaLiczba;
                licznikProb++;

                if (zgadywanaLiczba > wylosowanaLiczba) {
                    cout << "Za duza liczba!" << endl;
                }
                else if (zgadywanaLiczba < wylosowanaLiczba) {
                    cout << "Za mala liczba!" << endl;
                }
                else {
                    cout << "Gratulacje, " << nazwaGracza << "! Zgadles liczbe po " << licznikProb << " probach." << endl;
                    saveResult(nazwaGracza, licznikProb);
                }
            } while (zgadywanaLiczba != wylosowanaLiczba);

            wyjscie = true;
            break;
        }
        case 2:
            displayResults();
            break;
        case 3:
            wyjscie = true;
            break;
        default:
            cout << "Nieprawidlowa opcja. Sprobuj ponownie." << endl;
            break;
        }
    } while (!wyjscie);

    return 0;
}
