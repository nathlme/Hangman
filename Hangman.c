#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct{
    char word[35];
    char hiddenWord[35];
    char alreadyGuessed[26];
    int  count;
    int  tries;
    bool playing;
} Game;


void chooseWord(char *word){
    printf("==== Choisissez le mot a deviner ====\n"); 
    scanf("%s",word);

    printf("Mot choisi !\n");
}

void initHiddenWord(char *word, char *hiddenWord) {
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        hiddenWord[i] = '_';
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
        printf("Bien joue !\n");
    } else {
        printf("Mauvaise lettre !\n");
    }

    return found;
}


void launchGame(Game game) {
    char letter;

    while (game.count > 0 && strcmp(game.hiddenWord, game.word) != 0) {

        printf("\nMot actuel : %s\n", game.hiddenWord);
        printf("Essais restants : %d\n", game.count);
        printf("Lettre deja propose : ");
        
        for (int i = 0; i < strlen(game.alreadyGuessed); i++) {
            printf("%c,",game.alreadyGuessed[i]);
        }

        printf("\n\n\n==== Proposez une lettre ====\n");
        scanf(" %c", &letter);

        int found = revealLetter(game.word, game.hiddenWord, letter);
        game.alreadyGuessed[game.tries] = letter;
        game.tries++;

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
    printf(" ==== Menu ====\n");
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
            chooseWord(game.word);
            initHiddenWord(game.word, game.hiddenWord);
            break;
        case 2: 
            if (strlen(game.word) == 0) {
                printf("Tu dois d'abord choisir un mot !\n");
            } else {
                launchGame(game);
            }
            break;
        case 3:
            printf("envoie un message quand t'es rentrer !");
            break;
        default:
            printf("écrit mieux");
            break;
        } 
    } while (choice != 3);

    return 0;
}


 