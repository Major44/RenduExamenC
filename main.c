#define _CRT_SECURE_NO_WARNINGS
#include "vehiculeapp.h" //les prototypes des fonctions sont definit dans le fichier vehicule.h se trouvant dans le dossier Header Files

/*
SUJET : Le maire d�une petite ville vous a demand� de cr�er une application en langage C pour enregistrer
diff�rents types de v�hicules voitures g�n�rer des
statistiques de la circulation routi�re. 

Voici les fonctionnalit�s demand�es et les exigences techniques : 

Impl�menter au moins 10 fonctions diff�rentes (Ajouter, supprimer ou modifier, rechercher diff�rents types de v�hicules, avec de
nombreuses propri�t�s (marque, mod�le, ann�e, couleur, etc.) exigeant la d�claration de prototypes et qui seront plac�es apr�s  la fonction main()

Impl�menter des fonctions pour afficher des statistiques en fonction du type de v�hicule ou de
certaines propri�t�s (nombre de voitures rouges, etc.). 

Impl�menter des fonctions  pour afficher la liste compl�te des v�hicules enregistr�s dans la ville, Pouvoir rechercher un v�hicule enregistr� en utilisant des crit�res
comme le num�ro d�immatriculation, la marque.

*/

//Fonction principale Main
int main() {
    int choix = 0;

    while (choix != 10) {
        printf("\n=== Menu ===\n");
        printf("1. Ajouter un vehicule\n");
        printf("2. Supprimer un vehicule\n");
        printf("3. Modifier un vehicule\n");
        printf("4. Rechercher un vehicule\n");
        printf("5. Afficher la liste des vehicules\n");
        printf("6. Afficher les statistiques de circulation routiere\n");
        printf("7. Filtrer par marque\n");
        printf("8. Filtrer par annee\n");
        printf("9. Obtenir Nombre de Vehicule\n");
        printf("10. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
        case 1:
            ajouterVehicule();
            break;
        case 2:
            supprimerVehicule();
            break;
        case 3:
            modifierVehicule();
            break;
        case 4:
            rechercherVehicule();
            break;
        case 5:
            afficherVehicules();
            break;
        case 6:
            afficherStatistiques();
            break;
        case 7: {
            char marque[50];
            printf("Entrez la marque pour filtrer : ");
            scanf("%s", marque);
            filtrerParMarque(marque);
            break;
        }
        case 8: {
            int annee = 0;
            printf("Entrez l'annee pour filtrer par an : ");
            scanf("%s", annee);
            filtrerParAnnee(annee);
            break;
        }
        case 9: {
            int nb=0;
            obtenirNombreVehicules(nb);
            break;
        }
        case 10:
            printf("Merci d'avoir utilise l'application. Au revoir !\n");
            break;
        default:
            printf("Choix invalide. Veuillez reessayer.\n");
            break;
        }
    }
    return 0;
}