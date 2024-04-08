#include "ReadFile.h"
void menu(){
    int k = 0;
    
    while(k != 1){
        printf("\nThe game automatically writes the current state into a file");
        printf("\nIf you want to make a custom sprite, starta a new game, wait for it to create the save file, create the sprite there. \n 'O' means an alive cell and '#' means infected cell if the flood option is chosen");
        printf("\n Press X to toggle the flood in the game of life ");
        if(plague == 1) {
            printf("\n flood is currently toggled on");
        }
        printf("\n Press R to read the game from a file and start the game");
        printf("\n Press N to start a new game ");
        printf("\n Any other button closes the game\n");
        char input[1] = "";
        scanf("%s", &input[0]);
        switch (toupper(input[0]))
        {
        case 'X':
            if(plague == 1){
                plague = 0;
            }
            else {
                plague = 1;
            }
            break;
        case 'R':
            readFromFile();
            k=1;
            break;
        case 'N':
            firstWorld();
            k=1;
            break;
        default:
        exit(0);
            break;
        }
    }
}