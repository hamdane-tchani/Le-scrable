#include <iostream>
#include <fstream>
#include <algorithm>
#include "arbre_dictionnaire.hpp"

int main() {
    ArbreDictionnaire dictionnaire;

    // Chargement du dictionnaire à partir d'un fichier texte (un mot par ligne)
    std::ifstream fichier("/home/hamdane/Documents/l3Lyon/informatique/semestre2/apc/projet/scrabble-etu/src/dico.txt");
    if (!fichier) {
        std::cerr << "Erreur : impossible d'ouvrir le fichier dictionnaire.\n";
        return 1;
    }

    std::string mot;
    while (std::getline(fichier, mot)) {
        if (!mot.empty()) {
            dictionnaire.insererAvecPivot(mot);
        }
    }
    fichier.close();

    std::cout << "\n Dictionnaire chargé avec succès (formes GADDAG pivotées).\n";
    std::cout << " Vérification de quelques formes :\n\n";

    std::string exemples[] = {"CHAT","C+HAT", "C+HATS", "AHC+T", "UAETAB+","B+ATEA", "B+ATEAU", "R+E"};

    for (const auto& forme : exemples) {
        std::cout << "Forme : " << forme << " --> ";
        if (dictionnaire.contient(forme)) {
            std::cout << "présente \n";
        } else {
            std::cout << "absente \n";
        }
    } 
    std::cout << "   Fin du test.\n";


    return 0;
}
