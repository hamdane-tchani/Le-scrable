
#ifndef ARBRE_DICTIONNAIRE_HPP
#define ARBRE_DICTIONNAIRE_HPP

#include <unordered_map>
#include <string>

// Classe représentant un noeud dans un arbre de dictionnaire (préfixe/trie)
class Noeud {
public:
    bool estTerminal = false; // Indique si ce noeud termine un mot
    std::unordered_map<char, Noeud*> enfants; // Arêtes vers les lettres suivantes

    //~Noeud(); // destructeur pour libérer récursivement
};


/*

Pourquoi unordered_map<char, Noeud*> est bien choisi ici

    On peut facilement et rapidement savoir si une transition pour une lettre donnée existe.

    On peut créer dynamiquement de nouvelles transitions sans gaspiller de mémoire.

    Pas besoin de stocker explicitement la lettre dans le nœud, puisque c’est l’arête qui porte l’étiquette.

*/


// Classe de haut niveau représentant le dictionnaire complet
class ArbreDictionnaire {
public:
    ArbreDictionnaire();
    ~ArbreDictionnaire();

    Noeud* getRacine() const;
    void inserer(const std::string& mot);   // Ajoute un mot dans l’arbre
    bool contient(const std::string& mot) const; // Vérifie si un mot est présent
    void insererAvecPivot(const std::string& mot);   // Insère toutes les variantes GADDAG d’un mot

private:
    Noeud* racine; // point de départ de l’arbre
    void detruire(Noeud* noeud); // fonction récursive pour libérer la mémoire
};

#endif
