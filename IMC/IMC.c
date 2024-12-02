/* Fichier IMC.c
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   + Auteur(s) :    Jeremy Allemand                                        +
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   + Ce programme permet, pour une personne traitee:                       +
   +	  -. de saisir on poids en kg                                      +
   +	  - de saisir sa taille en metre.                                  +
   +	  - de calculer son indice de masse corporelle selon la formule    +
   +        imc = poids / (taille*taille)                                  +
   +	  - d'afficher son poids, sa taille, son imc et sa classification  +
   +        dependamment de son imc.                                       +
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   + Dernière mise à jour : 14 SEP 2024                                    +
   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/    
			   

#include <stdio.h>
#include <string.h>
#include <emscripten.h>                 
 				  
// Variable pour enregistrer le nombre de patients traités
int nbPatients = 0;

// Fonction pour calculer l'IMC et renvoyer la classification
EMSCRIPTEN_KEEPALIVE
const char* traiter_patient(float poids, float taille) {
    nbPatients++;
    static char resultat[256]; // Buffer pour stocker le message de retour
    float imc = poids / (taille * taille);

// Construire le message à retourner
    sprintf(resultat, "Poids : %.1f kg\nTaille : %.2f m\nIMC : %.1f\n", poids, taille, imc);
    if (imc < 18.5)
        sprintf(resultat + strlen(resultat), "Classification : MAIGREUR, RISQUE ÉLEVÉ À ACCRU\n");
    else if (imc < 25)
        sprintf(resultat + strlen(resultat), "Classification : POIDS NORMAL, RISQUE FAIBLE\n");
    else if (imc < 30)
        sprintf(resultat + strlen(resultat), "Classification : EMBONPOINT, RISQUE ÉLEVÉ\n");
    else
        sprintf(resultat + strlen(resultat), "Classification : OBÉSITÉ, RISQUE TRÈS ÉLEVÉ\n");

    return resultat; // Retourner le message
}

// Fonction pour obtenir le nombre total de patients traités
EMSCRIPTEN_KEEPALIVE
int obtenir_nombre_patients() {
    return nbPatients;
}
