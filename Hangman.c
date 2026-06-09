#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct{
    char word[35];
    char hiddenWord[35];
    char alreadyGuessed[27];
    int  count;
    int  tries;
} Game;


void printHangman(Game game) {
    switch (game.count) {
        case 9 :
            printf("\n______________");
            break;
        case 8 :
            for (int i = 0; i < 6; i++) {
                printf("      |\n");
            }
            printf("______________");
            break;
        case 7 :
            printf("   __________\n");
            for (int i = 0; i < 6; i++) {
                printf("      |\n");
            }
            printf("______________");
            break;
        case 6 :
            printf("   __________\n");
            printf("      |     |\n");
            for (int i = 0; i < 5; i++) {
                printf("      |\n");
            }
            printf("______________");
            break;
        case 5 :
            printf("   __________\n");
            printf("      |     |\n");
            printf("      |     O\n");
            for (int i = 0; i < 4; i++) {
                printf("      |\n");
            }
            printf("______________");
            break;
        case 4 :
            printf("   __________\n");
            printf("      |     |\n");
            printf("      |     O\n");
            printf("      |     |\n");
            for (int i = 0; i < 3; i++) {
                printf("      |\n");
            }
            printf("______________");
            break;
        case 3 :
            printf("   __________\n");
            printf("      |     |\n");
            printf("      |     O\n");
            printf("      |    /|\n");
            for (int i = 0; i < 3; i++) {
                printf("      |\n");
            }
            printf("______________");
            break;
        case 2 :
            printf("   __________\n");
            printf("      |     |\n");
            printf("      |     O\n");
            printf("      |    /|\\\n");
            for (int i = 0; i < 3; i++) {
                printf("      |\n");
            }
            printf("______________");
            break;
        case 1 :
            printf("   __________\n");
            printf("      |     |\n");
            printf("      |     O\n");
            printf("      |    /|\\\n");
            printf("      |    /\n");
            printf("      |\n");
            printf("      |\n");
            printf("______________");
            break;
        case 0:
            printf("   __________\n");
            printf("      |     |\n");
            printf("      |     O\n");
            printf("      |    /|\\\n");
            printf("      |    / \\\n");
            printf("      |\n");
            printf("      |\n");
            printf("______________");
            break;
    }
}


int isValidWord(char *word) {
    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return 0;
        }
    }

    return 1;
}


void chooseWord(char *word){
    do {
        printf("\n\n==== Choisissez le mot a deviner ====\n");
        scanf("%s", word);

        if (!isValidWord(word)) {
            printf("Erreur : le mot doit contenir uniquement des lettres.\n");
        }

    } while (!isValidWord(word));

    for (int i = 0; i < strlen(word); i++) {
        word[i] = tolower(word[i]);
    }

    printf("\nMot choisi !\n");
}

void initHiddenWord(char *word, char *hiddenWord) {
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        hiddenWord[i] = '-';
    }

    hiddenWord[length] = '\0';
}

int revealLetter(char *word, char *hiddenWord, char guessedLetter) {
    int length = strlen(word);
    int found = 0;

    for (int i = 0; i < length; i++) {
        if (word[i] == guessedLetter) {
            hiddenWord[i] = guessedLetter;
            found = 1;
        }
    }
    
    if (found) {
        system("cls");
        printf("Bien joue !\n");
    } else {
        system("cls");
        printf("Mauvaise lettre !\n");
    }

    return found;
}


int isAlreadyGuessed(char alreadyGuessed[], int tries, char letter) {
    for (int i = 0; i < tries; i++) {
        if (alreadyGuessed[i] == letter) {
            return 1;
        }
    }

    return 0;
}


void launchGame(Game game) {
    char letter;

    while (game.count > 0 && strcmp(game.hiddenWord, game.word) != 0) {

        printHangman(game);

        printf("\n\nMot actuel : %s\n", game.hiddenWord);
        printf("Essais restants : %d\n", game.count);
        printf("Lettre deja propose : ");
        

        for (int i = 0; i < game.tries; i++) {
            printf("%c", game.alreadyGuessed[i]);

            if (i < game.tries - 1) {
                printf(", ");
            }
        }

        do {
            printf("\n\n\n==== Proposez une lettre ====\n");
            scanf(" %c", &letter);
            letter = tolower(letter);
            if (!isalpha(letter)) {
                printf("\nErreur : Proposez uniquement des lettres.\n");
            }
        }while(!isalpha(letter));
        

        if (isAlreadyGuessed(game.alreadyGuessed, game.tries, letter)) {
            system("cls");
            printf("Tu as deja propose cette lettre ! Choisis-en une autre.\n");
            continue;
        }

        int found = revealLetter(game.word, game.hiddenWord, letter);
        game.alreadyGuessed[game.tries] = letter;
        game.tries++;
        game.alreadyGuessed[game.tries] = '\0';

        if (!found) {
            game.count--;
        }
    }

    if (strcmp(game.hiddenWord, game.word) == 0) {
        printf("Bravo, vous avez gagne ! Le mot etait : %s\n", game.word);
    } else {
        printHangman(game);
        printf("\n\nPerdu ! Le mot etait : %s\n", game.word);
    }
}

void printmenu () {
    printf("\n\n==== Menu ====\n");
    printf("1. Choisir le mot\n");
    printf("2. Lancer une partie\n");
    printf("3. Quitter le jeu\n");
    printf("\nVotre choix :\n");       
}

int main() {

    Game game;
    
    game.word[0] = '\0';
    game.hiddenWord[0] = '\0';
    game.alreadyGuessed[0] = '\0';
    game.count = 10;
    game.tries = 0;

    int choice;
    bool inMenu = true; 

    while(inMenu) {
        printmenu();
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            system("cls");
            chooseWord(game.word);
            initHiddenWord(game.word, game.hiddenWord);
            game.count = 10;
            game.tries = 0;
            game.alreadyGuessed[0] = '\0';
            break;
        case 2: 
            if (strlen(game.word) == 0) {
                printf("Tu dois d'abord choisir un mot !\n");
            } else {
                system("cls");
                launchGame(game);
            }
            break;
        case 3:
            system("cls");
            printf("a bientot !");
            inMenu = false;
            break;
        default:
            system("cls");
            printf("\n\n\ninput invalide ");
            break;
        } 
    };

    return 0;
}


 