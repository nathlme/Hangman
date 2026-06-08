#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


typedef struct{
    char word[35];
    char hiddenWord[35];
    char alreadyGuessed[26];
    int  count;
    int  tries;
    bool playing;
} Game;


void chooseWord(char *word){
    printf("\n\n==== Choisissez le mot a deviner ====\n"); 
    scanf("%s",word);

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

        printf("\nMot actuel : %s\n", game.hiddenWord);
        printf("Essais restants : %d\n", game.count);
        printf("Lettre deja propose : ");

        for (int i = 0; i < game.tries; i++) {
            printf("%c", game.alreadyGuessed[i]);

            if (i < game.tries - 1) {
                printf(", ");
            }
        }

        printf("\n\n\n==== Proposez une lettre ====\n");
        scanf(" %c", &letter);
        letter = tolower(letter);

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
        printf("Perdu ! Le mot etait : %s\n", game.word);
    }
}

void printmenu () {
    printf("\n\n==== Menu ====\n");
    printf("1. Choisir le mot\n");
    printf("2. Lancer une partie\n");
    printf("3. Quitter le jeu\n");
    printf("Votre choix :\n");       
}

int main() {

    Game game;
    
    game.word[0] = '\0';
    game.hiddenWord[0] = '\0';
    game.alreadyGuessed[0] = '\0';
    game.count = 10;
    game.tries = 0;
    game.playing = true;

    int choice;

    do {
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
            printf(" à bientôt !");
            break;
        default:
            system("cls");
            printf(" input invalide ");
            break;
        } 
    } while (choice != 3);

    return 0;
}


 