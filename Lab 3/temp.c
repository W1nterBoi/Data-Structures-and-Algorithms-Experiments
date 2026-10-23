#include <stdio.h>
#include <stdlib.h>

int **stageMat, **tileMat;
char ** displayMat;

int stageSize = 10;

void allocateMem(int ***matrix){
    *matrix = (int**) malloc(stageSize * sizeof(int*));
    for(int i = 0; i < stageSize; i++){
        (*matrix)[i] = (int*) malloc(stageSize * sizeof(int));
    }
}void allocateMemC(char ***matrix){
    *matrix = (char**) malloc(stageSize * sizeof(char*));
    for(int i = 0; i < stageSize; i++){
        (*matrix)[i] = (char*) malloc(stageSize * sizeof(char));
    }
}


void initMats(){
    for(int i = 0; i < stageSize; i++){
        for(int j = 0; j < stageSize; j++){
            
            stageMat[i][j] = 0;
            tileMat[i][j] = 0;
            displayMat[i][j] = ' ';
        }
    }
}

void initLiveCells(int arrSize, int arr[][2], int **stageMat, char **displayMat){
    for(int i = 0; i < arrSize; i++){
        int row = arr[i][0];
        int col = arr[i][1];
        stageMat[row][col] = 1;
        displayMat[row][col] = '@';
    }
}
    
void printMat(char **Mat){
    for(int i = 0; i < stageSize; i++){
        for(int j = 0; j < stageSize; j++){
            printf("%c ", Mat[i][j]);
        }
        printf("\n");
    }
}

void tileUpdate(int **stage, int **tile){
    for(int i = 0; i < stageSize; i++){
        for(int j = 0; j < stageSize; j++){
            int k = 0;
            for(int m = -1; m < 2; m++){
                for(int n = -1; n < 2; n++){
                    if(m == 0 && n == 0) continue;
                    else if( (i+m) >= stageSize || (j+n) >= stageSize || (i+m) < 0 || (j+n) < 0) continue;
                    else if(stage[i+m][j+n] == 1) k++; 
                }
            }
            tile[i][j] = k;
        }
    }

}

void stageUpdate(int **stage, int **tile, char **display){
    
}
    

int main(){
    allocateMem(&stageMat);
    allocateMem(&tileMat);
    allocateMem(&stageMat);
    initMats();
}
/* 
for(int i = 0; i < stageSize; i++){
    for(int j = 0; j < stageSize; j++){
    }
}
*/