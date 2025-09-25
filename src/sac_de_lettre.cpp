
#include "sac_de_lettres.hpp"
#include <stdexcept>

SacDeLettres::SacDeLettres() : generateur(static_cast<unsigned>(std::time(nullptr))) {
    // Initialisation des lettres avec leur quantité et leur valeur en points
    std::unordered_map<char, std::pair<int, int>> lettres = {
        {'A', {9, 1}}, {'B', {2, 3}}, {'C', {2, 3}}, {'D', {3, 2}}, {'E', {15, 1}},
        {'F', {2, 4}}, {'G', {2, 2}}, {'H', {2, 4}}, {'I', {8, 1}}, {'J', {1, 8}},
        {'K', {1, 10}}, {'L', {5, 1}}, {'M', {3, 2}}, {'N', {6, 1}}, {'O', {6, 1}},
        {'P', {2, 3}}, {'Q', {1, 8}}, {'R', {6, 1}}, {'S', {6, 1}}, {'T', {6, 1}},
        {'U', {6, 1}}, {'V', {2, 4}}, {'W', {1, 10}}, {'X', {1, 10}},
        {'Y', {1, 10}}, {'Z', {1, 10}}
    };

    // On remplit le vecteur des lettres restantes et la table des points
    for (const auto& [lettre, infos] : lettres) { 
        valeursDesLettres[lettre] = infos.second;
        lettresRestantes.insert(lettresRestantes.end(), infos.first, lettre);
        //On insère plusieurs fois la même lettre dans le vecteur lettresRestantes.
    //L’instruction insert(..., count, lettre) répète lettre count fois.
    // Ce modèle permet un tirage aléatoire fidèle à la probabilité de chaque lettre dans le vrai Scrabble.'
     //lettresRestantes.end() renvoie un itérateur qui pointe juste après le dernier élément du vecteur.
    // C’est l’endroit naturel pour ajouter quelque chose à la fin du vecteur avec insert() . On aurait pu utiliser push_back mais ceci est plus court

    }
} 

char SacDeLettres::tirer() {
    if (lettresRestantes.empty()) { 
        throw std::runtime_error("Le sac est vide.");
    } //Lancer une exception (erreur) avec le message "Le sac est vide."

    // Tirage uniforme dans le vecteur  
    std::uniform_int_distribution<> dist(0, lettresRestantes.size() - 1); //Cette classe uniform_int_distribution de la bibliotheque random génère un nombre entier aléatoire uniforme dans un intervalle [a, b].
    int index = dist(generateur); 
    char lettre = lettresRestantes[index];

    lettresRestantes[index] = lettresRestantes.back();
    lettresRestantes.pop_back();

    return lettre;
}
/*
    Ici, on utilise notre générateur pour produire un nombre aléatoire distribué uniformément.
    C’est un générateur pseudo-aléatoire basé sur l’algorithme Mersenne Twister 19937.
C’est une des meilleures méthodes de génération pseudo-aléatoire en C++ : Très rapide, très bonne uniformité.

mt19937 signifie “Mersenne Twister avec une période de 2¹⁹⁹³⁷ − 1”.

Et on l’initialise comme ça :
generateur(static_cast<unsigned>(std::time(nullptr)))

C’est-à-dire : on utilise l’heure actuelle en secondes comme graine (seed), pour que les tirages soient différents à chaque exécution.

*/
    // Suppression en O(1) : on remplace par le dernier élément et on coupe la fin
    


bool SacDeLettres::estVide() const {
    return lettresRestantes.empty();
}

int SacDeLettres::points(char lettre) const {
    auto it = valeursDesLettres.find(lettre);
    return (it != valeursDesLettres.end()) ? it->second : 0; //

}



// REMARQUE :
// Le tirage est rapide et uniforme grâce à std::uniform_int_distribution.
// L'accès au score d'une lettre est en O(1) grâce à la table de hachage.


/*

std::mt19937	Générateur aléatoire efficace (Mersenne Twister)
std::uniform_int_distribution	Pour tirer un entier uniformément
generateur(seed)	Graine initialisée avec l'heure (pour varier à chaque lancement)
erase()	Supprime proprement la lettre choisie, mais pas optimal (O(n))


*/

