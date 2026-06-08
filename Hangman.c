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























































































































































// fin du projet
 