#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int max(int **arr,size_t row, size_t col);
int rowSum(int **arr,size_t row,size_t col);
int columnSum(int **arr, size_t col_idx, size_t row);
int isSquare(size_t row, size_t col);
void displayOutputs(int **arr,size_t row,size_t col);

int** get_array(size_t row,size_t col);
void deallocate_array(int **arr, size_t row);

int main(){
    size_t row, col = 0;
    puts("Let's create a 2Dim array");
    printf("%s","How many rows? ");
    scanf("%zu",&row);
    printf("%s","How many columns? ");
    scanf("%zu",&col);

    int **arr = get_array(row,col);
    puts("");
    printf("Sum of row 1 = %d\n",rowSum(arr,0,col));
    printf("Sum of row 2 = %d\n",rowSum(arr,1,col));
    puts("");
    printf("Sum of column 1 = %d\n",columnSum(arr,0,col));
    printf("Sum of column 2 = %d\n",columnSum(arr,1,col));
    puts("");

    printf("This is %s array.\n",isSquare(row,col) ? "square" : "not square");
    displayOutputs(arr,row,col);
    deallocate_array(arr,row);
    return 0;
}

// TODO why need this?
int isSquare(size_t row, size_t col){
    return row == col;
}

void displayOutputs(int **arr,size_t row,size_t col){
    puts("Here is yiour 2Dim array:");
    for (size_t i = 0; i < row; i++){
        printf("%c",'[');
        for (size_t j = 0; j < col; j++){
            printf("%2d,",arr[i][j]);
        }
        printf("%c\n",']');
    }
}

int max(int **arr,size_t row, size_t col){
    int max = arr[0][0];
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < col; j++){
            if (arr[i][j] > max) max = arr[i][j];
        }
    }
    return max;
}

int rowSum(int **arr,size_t row_idx,size_t col){
    int sum = 0;
    for (size_t i = 0; i < col; i++)
        sum = sum + arr[row_idx][i];
    return sum;
}

int columnSum(int **arr, size_t col_idx, size_t row){
    int sum = 0;
    for (size_t i = 0; i < row; i++)
        sum += arr[i][col_idx];
    return sum;
}


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