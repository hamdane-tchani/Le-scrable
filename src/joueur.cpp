
#include "joueur.hpp"
#include <algorithm>

Joueur::Joueur(SacDeLettres& sac) {
    recharger(sac);
}

void Joueur::recharger(SacDeLettres& sac) {  // Tout est realise en O(1) donc il en est de meme pour recharger. Au pire, on a 7 itérations de traitements constants
    while (lettresEnMain.size() < 7 && !sac.estVide()) {
        lettresEnMain.push_back(sac.tirer());
    }
}

void Joueur::retirerLettre(char lettre) { //Complexité linéaire en n, mais ici n est très petit et fixe
    auto it = std::find(lettresEnMain.begin(), lettresEnMain.end(), lettre); 
    if (it != lettresEnMain.end()) {
        lettresEnMain.erase(it); // Suppression de la première occurrence
    }
}


/*

Le mot-clé auto veut dire : Laisse le compilateur deviner automatiquement le type de la variable it."
Ici, std::find(...) retourne un itérateur sur un élément du vecteur lettresEnMain. Le compilateur comprend ceci:
std::vector<char>::iterator it = std::find(...);

std::find(lettresEnMain.begin(), lettresEnMain.end(), lettre)
Il cherche la première occurrence de la lettre demandée dans la main.

Il retourne un itérateur vers cette lettre si elle existe, ou bien un itérateur vers lettresEnMain.end() si elle n'existe pas.
lettresEnMain.erase(it);
Supprime la lettre pointée par l’itérateur it.

*/


const std::vector<char>& Joueur::lettres() const {
    return lettresEnMain;
}

// REMARQUE :
// std::find + erase = O(n), mais n = 7 donc négligeable dans ce contexte.
// Design simple, mais efficace pour la gestion de la main.
