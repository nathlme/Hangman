#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct{
    char word[35];
    char hiddenWord[35];
    bool playing;
} Game;


void chooseWord(char *word){
    printf("==== Choisissez le mot a deviner ====\n"); 
    scanf("%s",word);

    printf("Mot choisi : %s\n",word);
}


void revealLetter(char *word, char *hiddenWord, char guessedLetter) {
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
}

int main() {
    char word[35];
    char hiddenWord[35];

    for (int i = 0; i < strlen(word); i++) {
        hiddenWord[i] = '_';
    }    
    hiddenWord[strlen(word)] = '\0';

    chooseWord(word);

    Game game;
    strcpy(game.word, word);
    strcpy(game.hiddenWord, hiddenWord);

    game.playing = true;

    return 0;    
}















































































































































// Partie de nicolas GRAAAOOOUU

void printmenu () {
printf(" ==== Menu ==== ");
printf("1. Choisir le mot ");
printf("2. Lancer une partie ");
printf("3. Quitter le jeu ");
printf(" Votre choix : ")       
}

int main () {
    word [0] = '\0';
    int choise;

    do {
        printmenu();
        scanf("%d",&choise);

        switch (choice)
        {
        case 1:
            chooseWord();
            break;
        case 2: 
            launchGame();
            break;
        case 3:
            printf("envoie un message quand t'es rentrer !")
        default:
            printf("écrit mieux")
            break;
        } while (choise != 3);
    }
    return 0
}






















































































































































// fin du projet
 