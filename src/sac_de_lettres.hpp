
#ifndef SAC_DE_LETTRES_HPP
#define SAC_DE_LETTRES_HPP

#include <vector>
#include <unordered_map>
#include <random>
#include <ctime>

// Classe représentant le sac de lettres du Scrabble
// - Utilise un vecteur pour contenir les lettres restantes, ce qui facilite un tirage uniforme.
// - La complexité d’un tirage est O(1) pour la sélection, 
// - Une table de hachage est utilisée pour l’association lettre → points (O(1)).

class SacDeLettres {
public:
    SacDeLettres();                       // Initialise le sac avec les lettres et leurs quantités
    char tirer();                         // Tire une lettre aléatoire selon la distribution
    bool estVide() const;                // Vérifie si le sac est vide
    int points(char lettre) const;       // Retourne la valeur d'une lettre

private:
    std::vector<char> lettresRestantes;  // Lettres disponibles dans le sac (avec répétition)
    std::unordered_map<char, int> valeursDesLettres; // Points associés à chaque lettre
    std::mt19937 generateur;             // Générateur de nombres aléatoires pour le tirage
};

#endif

