#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#define MAX_FAVORIS 5

typedef struct Livre {
    int id;
    char titre[50];
    char auteur[50];
    int est_disponible;
    struct Livre* suivant;
} Livre;

typedef struct {
    Livre* livres_favoris[MAX_FAVORIS];
    int compteur;
} LivresFavoris;

// Prototypes des fonctions
Livre* ajouter_livre(Livre* tete, int id, char* titre, char* auteur, int est_disponible);
Livre* supprimer_livre(Livre* tete, int id);
void modifier_livre(Livre* tete, int id, char* nouveau_titre, char* nouvel_auteur, int est_disponible);
Livre* rechercher_livre_par_id(Livre* tete, int id);
Livre* rechercher_livre_par_titre(Livre* tete, char* titre);
void afficher_livres(Livre* tete);
void initialiser_livres_favoris(LivresFavoris* favoris);
void ajouter_livre_favori(LivresFavoris* favoris, Livre* livre);
void afficher_livres_favoris(LivresFavoris* favoris);
void emprunter_livre(Livre* tete, LivresFavoris* favoris, int id);
void retourner_livre(Livre* tete, int id);

#endif
