# Projet Bibliothèque

## Description

Ce projet est un système de gestion de bibliothèque simple implémenté en C. Il permet aux utilisateurs de gérer une collection de livres, y compris l'ajout, la suppression, la modification, l'emprunt et le retour de livres. Il suit également les livres populaires en fonction des emprunts des utilisateurs.

## Fonctionnalités

- Ajouter de nouveaux livres à la bibliothèque
- Supprimer des livres de la bibliothèque
- Modifier les détails des livres (titre, auteur, disponibilité)
- Emprunter et retourner des livres
- Afficher tous les livres de la bibliothèque
- Afficher les livres les plus populaires en fonction de la fréquence d'emprunt

## Structure des fichiers

- `main.c` : Le fichier principal contenant le menu et la logique d'interaction utilisateur.
- `livre.h` : Le fichier d'en-tête définissant les structures et les prototypes de fonctions.
- `livre.c` : Le fichier d'implémentation contenant la logique de gestion des livres.

## Compilation

Pour compiler le projet, utilisez la commande suivante :

```bash
gcc -o bibliotheque main.c livre.c
