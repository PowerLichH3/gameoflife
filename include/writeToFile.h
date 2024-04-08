#ifdef _WIN32
#define OS 1
#endif
#ifdef __linux__
#define OS 2
#endif
void writeToFile(){
    
        FILE *file = fopen("./gameofsave.txt","w");
        for (int i = 0; i < WORLDROWS; i++)
        {
            for (int j = 0; j < WORLDCOLS; j++)
            {
                if(world[i][j].infected == 1 && (plague == 1)){
                    fputs("#",file);
                }
                if((world[i][j].current == 1) && (world[i][j].infected == 0)){
                    fputs("O",file);
                }
                else {
                    fputs(".",file);
                }
                
            }
            if(OS == 1) {
                fputs("\n",file);
            }
            if(OS == 2){
                fputs("\n",file);
            }
            
        }
    fclose(file);   
    
}