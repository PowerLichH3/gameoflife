void readFromFile(){
    FILE *file = fopen("./gameofsave.txt","r");
    char buffer[WORLDCOLS*WORLDROWS];
    while(fread(buffer, sizeof(buffer),1, file)==1);
    int y = 0;
    int x = 0;
    for (int i=0;buffer[i]!='\0';i++)
    {
        if(buffer[i] == 79) {
            world[y][x].current = 1;
            x++;
        }
        if(buffer[i] == 35){
            world[y][x].infected = 1;
            x++;
        }
        if(buffer[i] == 46) {
            world[y][x].current = 0;
            x++;
        }
        if(buffer[i] == 13){
            x++;
        }
        if(buffer[i] == 10){
            y++;
        }
    }
    fclose(file);
}