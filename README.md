# Jeu du Pendu en C

## Description

Ce projet est une implémentation du célèbre jeu du **Pendu** en langage C. Un joueur choisit un mot secret, puis un autre joueur tente de le deviner en proposant des lettres. À chaque erreur, une partie du pendu est dessinée jusqu'à ce que le joueur trouve le mot ou épuise tous ses essais.

---

## Fonctionnalités

* Menu interactif.
* Choix d'un mot secret.
* Vérification que le mot contient uniquement des lettres.
* Affichage progressif du pendu en ASCII.
* Affichage du mot caché avec des tirets.
* Gestion des lettres déjà proposées.
* Détection automatique de la victoire ou de la défaite.
* Gestion de la mémoire dynamique.

---

## Structure du programme

### Structure `Game`

```c
typedef struct{
    char word[35];
    char hiddenWord[35];
    char *alreadyGuessed;
    int count;
    int tries;
} Game;
```

| Champ            | Description                 |
| ---------------- | --------------------------- |
| `word`           | Mot à deviner               |
| `hiddenWord`     | Version masquée du mot      |
| `alreadyGuessed` | Lettres déjà proposées      |
| `count`          | Nombre d'essais restants    |
| `tries`          | Nombre de lettres proposées |

---

## Fonctions principales

### `printHangman(Game game)`

Affiche le dessin du pendu en fonction du nombre d'essais restants.

### `isValidWord(char *word)`

Vérifie que le mot choisi contient uniquement des lettres alphabétiques.

### `chooseWord(char *word)`

Permet au joueur de saisir le mot à deviner.

### `initHiddenWord(char *word, char *hiddenWord)`

Initialise le mot caché avec des tirets (`-`).

### `revealLetter(char *word, char *hiddenWord, char guessedLetter)`

Révèle les lettres correctement devinées dans le mot caché.

### `isAlreadyGuessed(char alreadyGuessed[], int tries, char letter)`

Vérifie si une lettre a déjà été proposée.

### `launchGame(Game game)`

Lance et gère le déroulement complet d'une partie.

### `printmenu()`

Affiche le menu principal.

---

## Compilation

Avec GCC :

```bash
gcc pendu.c -o pendu
```

---

## Exécution

Sous Windows :

```bash
pendu.exe
```

Sous Linux/macOS :

```bash
./pendu
```

---

## Utilisation

1. Choisir l'option **1** pour saisir le mot secret.
2. Choisir l'option **2** pour lancer la partie.
3. Proposer des lettres jusqu'à :

   * trouver le mot ➜ victoire ;
   * épuiser les essais ➜ défaite.
4. Choisir **3** pour quitter le programme.

---

## Limites connues

* La commande `system("cls")` fonctionne uniquement sous Windows.
* Le mot est visible lors de sa saisie (pas de masquage à l'écran).
* Taille maximale du mot : **34 caractères**.
* Le jeu est prévu pour deux joueurs sur le même ordinateur.

---

## Améliorations possibles

* Compatibilité Linux/macOS (`clear` au lieu de `cls`).
* Lecture des mots depuis un fichier dictionnaire.
* Mode solo avec mot aléatoire.
* Gestion des accents.
* Sauvegarde des scores.
* Interface graphique.
* Affichage coloré dans le terminal.

---

## Auteur

Projet réalisé en langage **C** dans le cadre de l'apprentissage des structures, tableaux, chaînes de caractères, mémoire dynamique et gestion des entrées utilisateur.
