#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livre.h"

Livre* ajouter_livre(Livre* tete, int id, char* titre, char* auteur, int est_disponible) {
    Livre* nouveau = (Livre*)malloc(sizeof(Livre));
    nouveau->id = id;
    strcpy(nouveau->titre, titre);
    strcpy(nouveau->auteur, auteur);
    nouveau->est_disponible = est_disponible;
    nouveau->suivant = tete;
    return nouveau;
}

Livre* supprimer_livre(Livre* tete, int id) {
    Livre* courant = tete;
    Livre* precedent = NULL;

    while (courant != NULL) {
        if (courant->id == id) {
            if (precedent == NULL) {
                tete = courant->suivant;
            } else {
                precedent->suivant = courant->suivant;
            }
            free(courant);
            printf("Livre avec ID %d supprimé.\n", id);
            return tete;
        }
        precedent = courant;
        courant = courant->suivant;
    }
    printf("Livre avec ID %d introuvable.\n", id);
    return tete;
}

void modifier_livre(Livre* tete, int id, char* nouveau_titre, char* nouvel_auteur, int est_disponible) {
    Livre* courant = tete;

    while (courant != NULL) {
        if (courant->id == id) {
            strcpy(courant->titre, nouveau_titre);
            strcpy(courant->auteur, nouvel_auteur);
            courant->est_disponible = est_disponible;
            printf("Livre avec ID %d modifié.\n", id);
            return;
        }
        courant = courant->suivant;
    }
    printf("Livre avec ID %d introuvable.\n", id);
}

Livre* rechercher_livre_par_id(Livre* tete, int id) {
    Livre* courant = tete;

    while (courant != NULL) {
        if (courant->id == id) {
            return courant;
        }
        courant = courant->suivant;
    }
    return NULL;
}

Livre* rechercher_livre_par_titre(Livre* tete, char* titre) {
    Livre* courant = tete;

    while (courant != NULL) {
        if (strcmp(courant->titre, titre) == 0) {
            return courant;
        }
        courant = courant->suivant;
    }
    return NULL;
}

void afficher_livres(Livre* tete) {
    Livre* courant = tete;

    while (courant != NULL) {
        printf("ID: %d, Titre: %s, Auteur: %s, Disponible: %s\n",
               courant->id, courant->titre, courant->auteur,
               courant->est_disponible ? "Oui" : "Non");
        courant = courant->suivant;
    }
}

void initialiser_livres_favoris(LivresFavoris* favoris) {
    favoris->compteur = 0;
    for (int i = 0; i < MAX_FAVORIS; i++) {
        favoris->livres_favoris[i] = NULL;
    }
}

void ajouter_livre_favori(LivresFavoris* favoris, Livre* livre) {
    if (favoris->compteur < MAX_FAVORIS) {
        favoris->livres_favoris[favoris->compteur++] = livre;
    }
}

void afficher_livres_favoris(LivresFavoris* favoris) {
    printf("Livres populaires :\n");
    for (int i = 0; i < favoris->compteur; i++) {
        if (favoris->livres_favoris[i] != NULL) {
            printf("ID: %d, Titre: %s, Auteur: %s\n",
                   favoris->livres_favoris[i]->id,
                   favoris->livres_favoris[i]->titre,
                   favoris->livres_favoris[i]->auteur);
        }
    }
}

void emprunter_livre(Livre* tete, LivresFavoris* favoris, int id) {
    Livre* livre = rechercher_livre_par_id(tete, id);
    if (livre == NULL) {
        printf("Livre avec ID %d introuvable.\n", id);
        return;
    }

    if (!livre->est_disponible) {
        printf("Livre déjà emprunté.\n");
    } else {
        livre->est_disponible = 0;  // Livre non disponible
        printf("Vous avez emprunté : %s\n", livre->titre);
        ajouter_livre_favori(favoris, livre);  // Ajout aux favoris
    }
}

void retourner_livre(Livre* tete, int id) {
    Livre* livre = rechercher_livre_par_id(tete, id);
    if (livre == NULL) {
        printf("Livre avec ID %d introuvable.\n", id);
        return;
    }

    if (livre->est_disponible) {
        printf("Ce livre n'a pas été emprunté.\n");
    } else {
        livre->est_disponible = 1;  // Livre de nouveau disponible
        printf("Merci d'avoir retourné : %s\n", livre->titre);
    }
}
