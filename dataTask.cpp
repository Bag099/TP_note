#include <iostream>
#include <map>

int main() {
    // Déclaration d'un dictionnaire
    std::map<std::string, int> monDictionnaire;

    // Ajout d'éléments
    monDictionnaire["clé1"] = 42;
    monDictionnaire["clé2"] = 123;
// Affichage des éléments
    std::cout << "Valeur associée à clé1 : " << monDictionnaire["clé1"] << std::endl;
    std::cout << "Valeur associée à clé2 : " << monDictionnaire["clé2"] << std::endl;

    return 0;
}
