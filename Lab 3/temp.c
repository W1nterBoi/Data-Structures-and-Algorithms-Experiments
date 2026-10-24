#include <stdio.h>
#include <stdlib.h>

int **stageMat, **tileMat;
char ** displayMat;

int stageSize = 50;

void allocateMem(int ***matrix){
    *matrix = (int**) malloc(stageSize * sizeof(int*));
    for(int i = 0; i < stageSize; i++){
        (*matrix)[i] = (int*) malloc(stageSize * sizeof(int));
    }
}
void allocateMemC(char ***matrix){
    *matrix = (char**) malloc(stageSize * sizeof(char*));
    for(int i = 0; i < stageSize; i++){
        (*matrix)[i] = (char*) malloc(stageSize * sizeof(char));
    }
}


void initMats(int **stage, int **tile, char ** display){
    for(int i = 0; i < stageSize; i++){
        for(int j = 0; j < stageSize; j++){
            stage[i][j] = 0;
            tile[i][j] = 0;
            display[i][j] = ' ';
        }
    }
}

void initLiveCells(int arrSize, int arr[][2], int **stage, char **display){
    for(int i = 0; i < arrSize; i++){
        int row = arr[i][0];
        int col = arr[i][1];
        stage[row][col] = 1;
        display[row][col] = '@';
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
                    else if(stage[i+m][j+n]) k++; 
                }
            }
            tile[i][j] = k;
        }
    }

}

void stageUpdate(int **stage, int **tile, char **display){
    for(int i = 0; i < stageSize; i++){
        for(int j = 0; j < stageSize; j++){
            //underpopulation
            if(tile[i][j] < 2){
                stage[i][j] = 0;
            }//survival
            else if(tile[i][j] < 4 && stage[i][j]){
                stage[i][j] = 1;
            }//overpopulation
            else if(tile[i][j] > 3){
                stage[i][j] = 0;
            }//reproduction
            if(tile[i][j] == 3 && !stage[i][j]){
                stage[i][j] = 1;
            }
            if(stage[i][j]) display[i][j] = '#';
            else display[i][j] = ' ';
        }
    }
    
}
    
void printSeperator(){
    for(int i = 0; i < stageSize; i++) printf("-");
}

int main(){
    allocateMem(&stageMat);
    allocateMem(&tileMat);
    allocateMemC(&displayMat);
    initMats(stageMat, tileMat, displayMat);
    int liveCells[4][2] = {{24, 25}, {24, 24}, {23, 25}, {25, 25}};
    initLiveCells(4, liveCells, stageMat, displayMat);

    printf("Age 0");
    printMat(displayMat);
    int n = 20;
    printSeperator();
    for(int i = 1; i <= n; i++){
        
        tileUpdate(stageMat, tileMat);
        stageUpdate(stageMat, tileMat, displayMat);
        printMat(displayMat);
        printSeperator();
    }

}
/* 
for(int i = 0; i < stageSize; i++){
    for(int j = 0; j < stageSize; j++){
    }
}
*/