
#include "arbre_dictionnaire.hpp"
#include <iostream>
#include <algorithm>  // pour std::reverse



ArbreDictionnaire::ArbreDictionnaire() {
    racine = new Noeud();
}

ArbreDictionnaire::~ArbreDictionnaire() {
    detruire(racine);
}

void ArbreDictionnaire::detruire(Noeud* noeud) {
    if (!noeud) return;
    for (auto& [_, enfant] : noeud->enfants) {
        detruire(enfant);
    }
    delete noeud;
}

Noeud* ArbreDictionnaire::getRacine() const {
    return racine;
}

//----------------------------------------

void ArbreDictionnaire::inserer(const std::string& mot) {
    Noeud* courant = racine;
    for (char c : mot) {
        if (courant->enfants.find(c) == courant->enfants.end()) {
            courant->enfants[c] = new Noeud();
        }
        courant = courant->enfants[c];
    }
    courant->estTerminal = true;
}

/*

Pour chaque lettre c du mot :

    On regarde si on a déjà une transition pour cette lettre.

    Si non : on crée un nouveau nœud et on l’ajoute dans enfants.

    On avance vers ce nœud suivant.

Quand on atteint la dernière lettre du mot :

    On marque le nœud comme terminal → il correspond à la fin d’un mot valide.

*/
//---------------------------------------

bool ArbreDictionnaire::contient(const std::string& mot) const {
    Noeud* courant = racine;
    for (char c : mot) {
        auto it = courant->enfants.find(c);
        if (it == courant->enfants.end()) {
            return false;
        }
        courant = it->second;
    }
    return courant->estTerminal;
}

//--------------------------------------------


// Cette méthode prend un mot et insère toutes ses formes GADDAG dans l’arbre.
// Chaque forme correspond à une manière de construire un mot autour d’un pivot (lettre déjà présente sur le plateau).
// Par exemple, pour "BATEAU" on insérera :
// "B+ATEAU", "AB+TEAU", "TAB+EAU", etc. en inversant la partie gauche du mot avant le pivot.
// Le + est le point de pivot entre la partie gauche (inversée) et la droite (normale).


void ArbreDictionnaire::insererAvecPivot(const std::string& mot) {
    if (mot.empty()) return;

    for (size_t pivot = 0; pivot <= mot.size(); ++pivot) {
        //std::string gauche = mot.substr(0, pivot); Meme chose que ce qui suit avec les iterateurs 
        std::string gauche(mot.begin(), mot.begin() + pivot);  // partie gauche du mot
        std::reverse(gauche.begin(), gauche.end());            // inversée pour exploration vers la gauche

        std::string droite(mot.begin() + pivot, mot.end());     // partie droite du mot

        std::string forme = gauche + '+' + droite;              // concatène forme complète
        inserer(forme);                                         // insère la forme dans le dictionnaire
    }
}

