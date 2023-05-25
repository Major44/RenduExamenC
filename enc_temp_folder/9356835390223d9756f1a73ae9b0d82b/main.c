#define _CRT_SECURE_NO_WARNINGS
#include "vehiculeapp.h" //les prototypes des fonctions sont definit dans le fichier vehicule.h se trouvant dans le dossier Header Files

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