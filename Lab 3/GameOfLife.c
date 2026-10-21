#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void allocateMem(int ***matrix, int row, int coloumn){
    *matrix = (int**) malloc(row * sizeof(int*));
    for(int i = 0; i < row; i++){
        (*matrix)[i] = (int*) malloc(coloumn * sizeof(int));
    }
}void allocateMemC(char ***matrix, int row, int coloumn){
    *matrix = (char**) malloc(row * sizeof(char*));
    for(int i = 0; i < row; i++){
        (*matrix)[i] = (char*) malloc(coloumn * sizeof(char));
    }
}


void printMatrix(int **matrix, int row, int coloumn){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < coloumn; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}void printMatrixC(char **matrix, int row, int coloumn){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < coloumn; j++){
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
void conwaythatshit(int **matrix, int **tile, char **display, int row, int coloumn){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < coloumn; j++){
            int k = 0;
            for(int m = -1; m < 2; m++){
                for(int n = -1; n < 2; n++){
                    if(n == 0 && m == 0){
                        continue;
                    } if ((i+m) >= row || (j+n) >= coloumn || (i+m) < 0 || (j+n) < 0){
                        continue;
                    }else if(matrix[i+m][j+n] == 1){
                        k++;
                    }
                }
            }
           
            //printf("%d %d %d \n", i+1, j+1, k);
            tile[i][j] = k;
        }
    }
 
    for(int i = 0; i < row; i++){
        for(int j = 0; j < coloumn; j++){
            if(tile[i][j] < 3){
                matrix[i][j] = 0;
                display[i][j] = ' ';
            } else{
                matrix[i][j] = 1;
                display[i][j] = '#';
            }
            //tile[i][j] = 0;
        }
    }
}



int main(){
    int **life, **tile;
    char **displayable;

    allocateMem(&life, 10, 10);
    allocateMem(&tile, 10, 10);
    allocateMemC(&displayable, 10, 10);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            life[i][j] = 0;
            tile[i][j] = 0;
            displayable[i][j] = ' ';
        }
    }

    life[4][4] = 1;
    life[5][4] = 1;
    life[4][5] = 1;
    life[3][3] = 1; 
    printf("\nAge Zero\n");
    printMatrixC(displayable, 10, 10);

    printf("\nAge One\n");
    conwaythatshit(life, tile, displayable, 10, 10);
    printMatrixC(displayable, 10, 10);
    //printf("\nTile\n");
    //printMatrix(tile, 10, 10);
    
    printf("\nAge Two\n");
    conwaythatshit(life, tile, displayable, 10, 10);
    printMatrixC(displayable, 10, 10);
    //printf("\nTile\n");
    //printMatrix(tile, 10, 10);
    
    printf("\nAge Three\n");
    conwaythatshit(life, tile, displayable, 10, 10);
    printMatrixC(displayable, 10, 10);
    //printf("\nTile\n");
    //printMatrix(tile, 10, 10);
    return 0;
}