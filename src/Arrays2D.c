#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

size_t row, col = 0;

int max(int arr[][col],size_t row, size_t col);
int rowSum(int arr[][col],size_t row,size_t col);
int columnSum(int arr[][col], size_t col_idx, size_t row);
int isSquare(size_t row, size_t col);
void displayOutputs(int arr[][col],size_t row,size_t col);
void demo(size_t row, size_t col);


int main(){
    puts("Let's create a 2Dim array");
    printf("%s","How many rows? ");
    scanf("%zu",&row);
    printf("%s","How many columns? ");
    scanf("%zu",&col);

    demo(row,col);
    return 0;
}

// display 2d array
void displayOutputs(int arr[][col],size_t row,size_t col){
    puts("Here is yiour 2Dim array:");
    for (size_t i = 0; i < row; i++){
        printf("%c",'[');
        for (size_t j = 0; j < col; j++){
            printf("%2d,",arr[i][j]);
        }
        printf("%c\n",']');
    }
}

// demo 2d array
void demo(size_t row, size_t col){
    int arr[row][col];
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < col; j++){
            printf("enter [%lu][%lu] ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Max of array is %d\n",max(arr,row,col));
    puts("");
    for (size_t i = 0; i < row; i++)
        printf("Sum of row %lu = %d\n",i,rowSum(arr,i,col));
    puts("");
    for (size_t i = 0; i < col; i++)
        printf("Sum of column %lu = %d\n",i,columnSum(arr,i,col));
    puts("");

    printf("This is %s array.\n",isSquare(row,col) ? "square" : "not square");
    displayOutputs(arr,row,col);
}

// check 2d array square array
int isSquare(size_t row, size_t col){
    return row == col;
}

// get max value of 2d array
int max(int arr[][col],size_t row, size_t col){
    int max = arr[0][0];
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < col; j++){
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    return max;
}

// get sum of row
int rowSum(int arr[][col],size_t row_idx,size_t col){
    int sum = 0;
    for (size_t i = 0; i < col; i++)
        sum = sum + arr[row_idx][i];
    return sum;
}

// get sum of col
int columnSum(int arr[][col], size_t col_idx, size_t row){
    int sum = 0;
    for (size_t i = 0; i < row; i++)
        sum += arr[i][col_idx];
    return sum;
}

/*

int** get_array(size_t row,size_t col){
    int input = 0;
    int **array = (int **)malloc(row * sizeof(int *));

    for (size_t i = 0; i < row; i++){
        array[i] = (int *)malloc(col * sizeof(int));
        for (size_t j = 0; j < col; j++){
            printf("enter [%lu][%lu] ",i,j);
            scanf("%d",&input);
            array[i][j] = input;
        }
    }
    return array;
}

void deallocate_array(int **arr, size_t row){
    for (size_t i = 0; i < row; i++){
        free(arr[i]);
    }
    free(arr);
}

int **getArray(size_t row,size_t col){
    size_t row, col = 0;
    puts("Let's create a 2Dim array");
    printf("%s","How many rows? ");
    scanf("%zu",&row);
    printf("%s","How many columns? ");
    scanf("%zu",&col);
    int arr[row][col];
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < col; j++){
            printf("enter [%lu][%lu] ",i,j);
            scanf("%d",&arr[i][j]);
        }
    }
    return arr;
}

*/

