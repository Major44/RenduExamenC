#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "vehiculeapp.h" 

//Declaration de la structure vehicule
typedef struct {
    char marque[50];
    char modele[50];
    int annee;
    char couleur[20];
    char immatriculation[20];
    char type[20];
} Vehicule;

//Construction du type de vehicule

Vehicule VarVehicule[100];
int nombreVehicules = 0;

//Fonction pour ajouter un vehicule

void ajouterVehicule() {
    if (nombreVehicules < 100) {
        Vehicule nouveauVehicule;
        printf("Marque: ");
        scanf("%s", nouveauVehicule.marque);
        printf("Modele: ");
        scanf("%s", nouveauVehicule.modele);
        printf("Annee: ");
        scanf("%d", &nouveauVehicule.annee);
        printf("Couleur: ");
        scanf("%s", nouveauVehicule.couleur);
        printf("Immatriculation: ");
        scanf("%s", nouveauVehicule.immatriculation);

        VarVehicule[nombreVehicules++] = nouveauVehicule;

        printf("Vehicule ajouter avec succes.\n");
    }
    else {
        printf("Impossible d'ajouter plus de vehicules.\n");
    }
}
//Fonction pour supprimer un vehicule
void supprimerVehicule() {
    char immatriculation[20];
    printf("entrez l'immatriculation du vehicule a supprimer: ");
    scanf("%s", immatriculation);

    int vehiculeTrouve = 0;
    for (int i = 0; i < nombreVehicules; i++) {
        if (strcmp(VarVehicule[i].immatriculation, immatriculation) == 0) {
            printf("Vehicule supprime :\n");
            printf("Marque: %s\n", VarVehicule[i].marque);
            printf("Modele: %s\n", VarVehicule[i].modele);
            printf("Annee: %d\n", VarVehicule[i].annee);
            printf("Couleur: %s\n", VarVehicule[i].couleur);
            printf("Immatriculation: %s\n", VarVehicule[i].immatriculation);

            for (int j = i; j < nombreVehicules - 1; j++) {
                VarVehicule[j] = VarVehicule[j + 1];
            }

            nombreVehicules--;

            printf("Vehicule supprime avec succes.\n");

            vehiculeTrouve = 1;
            break;
        }
    }

    if (!vehiculeTrouve) {
        printf("Aucun vehicule trouve avec cette immatriculation.\n");
    }
}

//Fonction pour ajouter un vehicule
void modifierVehicule() {
    char immatriculation[20];
    printf("entrez l'immatriculation du vehicule a modifier: ");
    scanf("%s", immatriculation);

    int vehiculeTrouve = 0;
    for (int i = 0; i < nombreVehicules; i++) {
        if (strcmp(VarVehicule[i].immatriculation, immatriculation) == 0) {
            printf("Vehicule trouve :\n");
            printf("Marque: %s\n", VarVehicule[i].marque);
            printf("Modele: %s\n", VarVehicule[i].modele);
            printf("Annee: %d\n", VarVehicule[i].annee);
            printf("Couleur: %s\n", VarVehicule[i].couleur);
            printf("Immatriculation: %s\n", VarVehicule[i].immatriculation);

            printf("Nouvelles informations :\n");
            printf("Marque: ");
            scanf("%s", VarVehicule[i].marque);
            printf("Modele: ");
            scanf("%s", VarVehicule[i].modele);
            printf("Annee: ");
            scanf("%d", &VarVehicule[i].annee);
            printf("Couleur: ");
            scanf("%s", VarVehicule[i].couleur);

            printf("Vehicule modifie avec succes.\n");

            vehiculeTrouve = 1;
            break;
        }
    }

    if (!vehiculeTrouve) {
        printf("Aucun vehicule trouve avec cette immatriculation.\n");
    }
}
//Fonction pour rechercher un vehicule
void rechercherVehicule() {
    char immatriculation[20];
    printf("entrez l'immatriculation du vehicule a rechercher: ");
    scanf("%s", immatriculation);

    int vehiculeTrouve = 0;
    for (int i = 0; i < nombreVehicules; i++) {
        if (strcmp(VarVehicule[i].immatriculation, immatriculation) == 0) {
            printf("Vehicule trouve :\n");
            printf("Marque: %s\n", VarVehicule[i].marque);
            printf("Modele: %s\n", VarVehicule[i].modele);
            printf("Annee: %d\n", VarVehicule[i].annee);
            printf("Couleur: %s\n", VarVehicule[i].couleur);
            printf("Immatriculation: %s\n", VarVehicule[i].immatriculation);
            vehiculeTrouve = 1;
            break;
        }
    }

    if (!vehiculeTrouve) {
        printf("Aucun vehicule trouve avec cette immatriculation.\n");
    }
}

//Fonction pour afficher un vehicule

void afficherVehicules() {
    if (nombreVehicules == 0) {
        printf("Aucun vehicule enregistre.\n");
    }
    else {
        printf("Liste des vehicules enregistres:\n");
        for (int i = 0; i < nombreVehicules; i++) {
            printf("Vehicule %d:\n", i + 1);
            printf("Marque: %s\n", VarVehicule[i].marque);
            printf("Modele: %s\n", VarVehicule[i].modele);
            printf("Annee: %d\n", VarVehicule[i].annee);
            printf("Couleur: %s\n", VarVehicule[i].couleur);
            printf("Immatriculation: %s\n", VarVehicule[i].immatriculation);
        }
    }
}
//Fonction pour afficher les statistique 
void afficherStatistiques() {
    int nbVoituresRouges = 0;
    int nbMotos = 0;

    for (int i = 0; i < nombreVehicules; i++) {
        if (strcmp(VarVehicule[i].couleur, "rouge") == 0 && strcmp(VarVehicule[i].type, "voiture") == 0) {
            nbVoituresRouges++;
        }
        if (strcmp(VarVehicule[i].type, "moto") == 0) {
            nbMotos++;
        }
    }
    printf("Statistiques de circulation routiere :\n");
    printf("Nombre de voitures rouges : %d\n", nbVoituresRouges);
}

void filtrerParMarque(const char* marque) {
    int vehiculesTrouves = 0;

    printf("Vehicules de la marque %s :\n", marque);
    for (int i = 0; i < nombreVehicules; i++) {
        if (strcmp(VarVehicule[i].marque, marque) == 0) {
            printf("Vehicule %d:\n", i + 1);
            printf("Marque: %s\n", VarVehicule[i].marque);
            printf("Modele: %s\n", VarVehicule[i].modele);
            printf("Annee: %d\n", VarVehicule[i].annee);
            printf("Couleur: %s\n", VarVehicule[i].couleur);
            printf("Immatriculation: %s\n", VarVehicule[i].immatriculation);
            vehiculesTrouves++;
        }
    }

    if (vehiculesTrouves == 0) {
        printf("Aucun vehicule trouve de la marque %s.\n", marque);
    }
}

void filtrerParAnnee(int annee) {
    int vehiculesTrouves = 0;

    printf("Vehicules de l'annee %d :\n", annee);
    for (int i = 0; i < nombreVehicules; i++) {
        if (VarVehicule[i].annee == annee) {
            printf("Vehicule %d:\n", i + 1);
            printf("Marque: %s\n", VarVehicule[i].marque);
            printf("Modele: %s\n", VarVehicule[i].modele);
            printf("Annee: %d\n", VarVehicule[i].annee);
            printf("Couleur: %s\n", VarVehicule[i].couleur);
            printf("Immatriculation: %s\n", VarVehicule[i].immatriculation);
            vehiculesTrouves++;
        }
    }

    if (vehiculesTrouves == 0) {
        printf("Aucun vehicule trouve de l'annee %d.\n", annee);
    }
}

void triParAnnee() {
    // Tri des vehicules par ordre croissant d'annee
    for (int i = 0; i < nombreVehicules - 1; i++) {
        for (int j = 0; j < nombreVehicules - i - 1; j++) {
            if (VarVehicule[j].annee > VarVehicule[j + 1].annee) {
                Vehicule temp = VarVehicule[j];
                VarVehicule[j] = VarVehicule[j + 1];
                VarVehicule[j + 1] = temp;
            }
        }
    }

    printf("Liste des vehicules tries par annee :\n");
    for (int i = 0; i < nombreVehicules; i++) {
        printf("Vehicule %d:\n", i + 1);
        printf("Marque: %s\n", VarVehicule[i].marque);
        printf("Modele: %s\n", VarVehicule[i].modele);
        printf("Annee: %d\n", VarVehicule[i].annee);
        printf("Couleur: %s\n", VarVehicule[i].couleur);
        printf("Immatriculation: %s\n", VarVehicule[i].immatriculation);
    }
}
int obtenirNombreVehicules() {
           return nombreVehicules;
}
