#include <stdio.h>
#include <stdlib.h>
#include "livre.h"

void afficher_menu() {
    printf("\n=== Menu Bibliothèque ===\n");
    printf("1. Ajouter un livre\n");
    printf("2. Supprimer un livre\n");
    printf("3. Modifier les informations d'un livre\n");
    printf("4. Emprunter ou retourner un livre\n");
    printf("5. Afficher tous les livres\n");
    printf("6. Afficher les livres populaires\n");
    printf("0. Quitter\n");
    printf("Choisissez une option : ");
}

int main() {
    Livre* bibliotheque = NULL;
    LivresFavoris favoris;
    initialiser_livres_favoris(&favoris);

    int choix, id, est_disponible;
    char titre[50], auteur[50];

    do {
        afficher_menu();
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                printf("ID du livre : ");
                scanf("%d", &id);
                printf("Titre : ");
                scanf(" %[^\n]s", titre);
                printf("Auteur : ");
                scanf(" %[^\n]s", auteur);
                printf("Disponible (1 = oui, 0 = non) : ");
                scanf("%d", &est_disponible);
                bibliotheque = ajouter_livre(bibliotheque, id, titre, auteur, est_disponible);
                break;
            case 2:
                printf("ID du livre à supprimer : ");
                scanf("%d", &id);
                bibliotheque = supprimer_livre(bibliotheque, id);
                break;
            case 3:
                printf("ID du livre à modifier : ");
                scanf("%d", &id);
                printf("Nouveau titre : ");
                scanf(" %[^\n]s", titre);
                printf("Nouvel auteur : ");
                scanf(" %[^\n]s", auteur);
                printf("Disponible (1 = oui, 0 = non) : ");
                scanf("%d", &est_disponible);
                modifier_livre(bibliotheque, id, titre, auteur, est_disponible);
                break;
            case 4:
                printf("1. Emprunter un livre\n");
                printf("2. Retourner un livre\n");
                printf("Choisissez une option : ");
                scanf("%d", &est_disponible);
                printf("ID du livre : ");
                scanf("%d", &id);
                if (est_disponible == 1) {
                    emprunter_livre(bibliotheque, &favoris, id);
                } else if (est_disponible == 2) {
                    retourner_livre(bibliotheque, id);
                }
                break;
            case 5:
                afficher_livres(bibliotheque);
                break;
            case 6:
                afficher_livres_favoris(&favoris);
                break;
            case 0:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide, réessayez.\n");
        }
    } while (choix != 0);

    return 0;
}
