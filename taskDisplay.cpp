#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <iomanip>

int main() {
    int x;
    std::string action; // Ajout de la déclaration de la variable action
    std::cout << "Inserer un nombre entier ici: " << std::endl;
    std::cin >> x;
    std::cin.ignore(); // Ignorer le caractère de nouvelle ligne restant après cin

        std::map<std::string, bool> mon_dictionnaire;
        std::string cle;
        bool termine = false;

        // Ajouter des éléments au dictionnaire
        mon_dictionnaire["tache1"] = false;
        mon_dictionnaire["tache2"] = false;

        // Afficher les tâches à faire
        std::cout << "Tâches à faire : " << std::endl;
        for (const auto& paire : mon_dictionnaire) {
            if (!paire.second) {
                std::cout << paire.first << std::endl;
            }
        }

        // Demander à l'utilisateur de marquer une tâche comme terminée
        std::cout << "Entrez la tâche terminée : ";
        std::getline(std::cin, cle);

        // Vérifier si la tâche existe dans le dictionnaire
        if (mon_dictionnaire.find(cle) != mon_dictionnaire.end()) {
            mon_dictionnaire[cle] = true;
            std::cout << "La tâche '" << cle << "' a été marquée comme terminée." << std::endl;
        } else {
            std::cout << "La tâche '" << cle << "' n'existe pas dans le dictionnaire." << std::endl;
        }

        // Supprimer les tâches terminées du dictionnaire
        for (auto it = mon_dictionnaire.begin(); it != mon_dictionnaire.end();) {
            if (it->second) {
                it = mon_dictionnaire.erase(it);
            } else {
                ++it;
            }
        }

        // Afficher les tâches restantes à faire
        std::cout << "Tâches restantes à faire : " << std::endl;
        for (const auto& paire : mon_dictionnaire) {
            std::cout << paire.first << std::endl;
        }
        // Demander à l'utilisateur s'il souhaite sauvegarder
        std::cout << "Voulez-vous sauvegarder ce que vous avez fait ? (oui/non) : ";
        std::getline(std::cin, action);

        if (action == "oui") {
            // Ouvrir un fichier en mode écriture
            std::ofstream fichier("sauvegarde.txt");

            if (fichier.is_open()) {
                // Écrire dans le fichier
                fichier << "Ce que vous avez fait a été sauvegardé." << std::endl;
                std::cout << "Sauvegarde effectuée avec succès." << std::endl;

                // Fermer le fichier
                fichier.close();
            } else {
                std::cerr << "Erreur lors de l'ouverture du fichier pour sauvegarde." << std::endl;
            }
        } else if (action == "non") {
            std::cout << "Vous avez choisi de ne pas sauvegarder." << std::endl;
        } else {
            std::cerr << "Réponse invalide. Veuillez répondre 'oui' ou 'non'." << std::endl;
        }

    return 0;
}
