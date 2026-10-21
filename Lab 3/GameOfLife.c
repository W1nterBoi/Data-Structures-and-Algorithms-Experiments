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

void progressAge(int **matrix, int **tile, char **display, int row, int coloumn){
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
                display[i][j] = '@';
            }
            //tile[i][j] = 0;
        }
    }
}

void assignAlive(int **life, char **displayable, int row, int coloumn){
    life[row][coloumn] = 1;
    displayable[row][coloumn] = '@';
}


int main(){
    int **life, **tile;
    char **displayable;

    int worldW, worldB;

    printf("Enter Breadth and Width of World: ");
    scanf("%d %d", &worldB, &worldW);

    allocateMem(&life, worldB, worldW);
    allocateMem(&tile, worldB, worldW);
    allocateMemC(&displayable, worldB, worldW);
    for (int i = 0; i < worldB; i++) {
        for (int j = 0; j < worldW; j++) {
            life[i][j] = 0;
            tile[i][j] = 0;
            displayable[i][j] = ' ';
        }
    }

    assignAlive(life, displayable, 4, 5); 
    assignAlive(life, displayable, 5, 5); 
    assignAlive(life, displayable, 4, 4); 
    assignAlive(life, displayable, 5, 4); 

    int ages;

    printf("Length of Simulation (In Ages) : ");
    scanf("%d", &ages);

    printf("\nAge 0\n");
    printMatrixC(displayable, worldB, worldW);

    for(int i = 1; i <= ages; i++){
        printf("\nAge %d\n", i);
        progressAge(life, tile, displayable, worldB, worldW);
        printMatrixC(displayable, worldB, worldW);
    }

    return 0;
}