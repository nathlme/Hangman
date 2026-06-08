#include <stdio.h>
#include <stdlib.h>
#include <string.h>



















































































































































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
 