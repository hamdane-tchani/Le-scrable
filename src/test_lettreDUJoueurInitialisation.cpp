#include<iostream>

#include<unordered_map> 

#include "sac_de_lettres.hpp"


using namespace std;


int main() {
 
SacDeLettres sac;


printf("Tirage de 7 lettres :\n");
for(int i=0; i<7; i++) {
    char lettre = sac.tirer();
    int points = sac.points(lettre);
    printf("Lettre tirée : %c (Points : %d)\n", lettre, points);
}   



  return 0 ;
}