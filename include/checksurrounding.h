int checkSurrounding(int currentRow, int currentCol){
    int count = 0;
    
    for (int i = currentRow-1; i <= currentRow+1; i++)
    {
        for (int j = currentCol-1; j <= currentCol+1; j++)
        {
            if((i == currentRow && j == currentCol) || (i<0 || j<0) || (i>=WORLDROWS || j>=WORLDCOLS) ){
                continue;
                
            }
            if(world[i][j].current == 1) {
                count++;
                
            }
            if((world[i][j].infected == 0) && (world[currentRow][currentCol].infected ==1) && (plague == 1)) {
                int temprand = rand() %4-1;
                if(temprand ==1){
                    world[i][j].infected = 1;
                }
            }
            if((world[currentRow][currentCol].infected==1) && (plague == 1)){
            int temprand = rand() % 500-1;
            if(temprand==1){
                world[i][j].infected=1;
            }

            }

            
        }
    }
    

    if (count==3 || (count==2 && (world[currentRow][currentCol].current == 1))){
        return 1;
        
    }
    else if(count<2 || count>3) {
        return 0;
    }
}