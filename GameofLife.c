#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>
#include "include/firstworld.h"
#include "include/menu.h"
#include "include/writeToFile.h"
#include "include/checksurrounding.h"
#define WORLDROWS 20
#define WORLDCOLS 40





void newWorld(){
    for(int i = 0; i<WORLDROWS; i++){
        for (int j = 0; j < WORLDCOLS; j++)
        {
            world[i][j].current = world[i][j].future;
        }
        
    }
}
void printWorld(){
    printf("\n");
    for (int i = 0; i < WORLDROWS; i++)
    {
        printf("|");
        for (int j = 0; j < WORLDCOLS; j++)
        {
            if(world[i][j].infected ==1 && (plague == 1)){
                printf("#");
            }
            else if(world[i][j].current == 1) {
                printf("O");
            }
            else {
                printf(".");
            }
            
        }
        printf("|\n");
        
    }
}
void Life(void) {
    
    printWorld();
    
    for (int i = 0; i < WORLDROWS; i++)
    {
        for (int j = 0; j < WORLDCOLS; j++)
        {
            
            world[i][j].future = checkSurrounding(i,j);
        }
        
    }
    newWorld();
    
}




int main(void) {
    menu();
    srand(time(NULL));
    while(1){
        Life();
        sleep(1);
        writeToFile();
        system("cls"); // empties terminal so it looks nicer :)
    }
    
}