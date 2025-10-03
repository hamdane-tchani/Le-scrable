
#ifndef JOUEUR_HPP
#define JOUEUR_HPP

#include "sac_de_lettres.hpp"

// Classe représentant la main d'un joueur (7 lettres maximum)
//  Utilise un vecteur pour modéliser la main
//  Rechargement automatique via appel au sac

class Joueur {
public:
    Joueur(SacDeLettres& sac);              // Initialise une main en tirant 7 lettres
    void recharger(SacDeLettres& sac);      // Recharge jusqu'à 7 lettres
    void retirerLettre(char lettre);        // Retire une lettre jouée
    const std::vector<char>& lettres() const; // Retourne les lettres en main

private:
    std::vector<char> lettresEnMain;        // Lettres actuellement disponibles pour jouer
};

#endif

// REMARQUE :
// Les opérations sur le vecteur sont simples : accès, suppression, ajout → toutes en O(n) ou mieux.
// Suffisant ici, car la taille est petite (7 lettres).

