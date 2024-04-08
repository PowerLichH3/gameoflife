#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>


#define WORLDROWS 20
#define WORLDCOLS 40
int plague = 0;
struct organism {
    int current;
    int future;
    int infected;
};
struct organism world[WORLDROWS][WORLDCOLS];


void firstWorld(){
    for(int i = 0; i<WORLDROWS; i++){
        for (int j = 0; j < WORLDCOLS; j++)
        {
            int randtemp = rand() %1000-1;
            if(randtemp==1 && plague == 1){
                world[i][j].infected=1;
            }
            world[i][j].current = 0;
        }
        
    }
    //Oscillator created as a sacrificial gift 
    world[3][0].current = 1;
    world[3][1].current = 1;
    world[3][2].current = 1;
    world[3][3].current = 1;

}