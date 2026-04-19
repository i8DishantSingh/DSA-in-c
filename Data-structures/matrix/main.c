#include<stdio.h>

int main() {
    int i, j;
    int rows, columns;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &columns);

    int mat[rows][columns];

    printf("\nEnter the elements in marix: \n");
    for(i=0;i<rows;i++){
        printf("Row no. %d:- ", i);
        for(j=0;j<columns;j++){
            scanf("%d", &mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("-----Matrix-----\n");

    for(i=0;i<rows;i++){
        
        for(j=0;j<columns;j++){
            printf("%d  ", mat[i][j]);
        }
        printf("\n");
    }

    
}