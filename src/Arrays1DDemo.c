#include <stdio.h>
#include <stdlib.h>
/*
Tony Siu
9/14/2023
CIS 2107
Lab 4: Arrays
*/
// function prototypes
void fillArray(int arr[],unsigned int size,int rand_min,int rand_max);
int findWithRange(int array[],unsigned int size,unsigned int lowSelectedRange,unsigned int highSelectedRange);
void reverseArray(int array[], unsigned int size);
void reverseSelectedRangeWithinArray(int array[],unsigned int size,unsigned int startRange,unsigned int endRange);
int findSequence(int arr[],unsigned int size,int tom,int jerry);


// gcc -o executables/arrays -g src/Arrays1DDemo.c
int main(){
    unsigned int size = 10;
    int arr[10] = {0};
    fillArray(arr,size,0,10);
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("max: %d\n",findWithRange(arr,size,5,10));
    reverseArray(arr,10);
    for(int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    reverseSelectedRangeWithinArray(arr,10,0,5);
    for(int i = 0; i < 10; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("No 10 0 tom jerry pair %d\n",findSequence(arr,size,0,10));
    printf("Tom jerry pair from %d index\n",findSequence(arr,size,arr[4],arr[5]));
    return 0;
}

// fill array with random numbers between min and max
void fillArray(int arr[],unsigned int size,int rand_min,int rand_max){
    // int *array = malloc(size * sizeof(int));
    for(unsigned int i = 0; i < size; i++){
        arr[i] = rand_min + rand() % (rand_max - rand_min + 1);
    }
}

// find the max value within a range of indices of an array
int findWithRange(int array[],unsigned int size,unsigned int lowSelectedRange,unsigned int highSelectedRange){
    if (highSelectedRange > size || lowSelectedRange < 0 || lowSelectedRange > highSelectedRange)
        return -1;
    int max = 0;

    for(unsigned int i = 0; (lowSelectedRange + i) < highSelectedRange; i++){
        if(array[lowSelectedRange + i] > max)
            max = array[lowSelectedRange + i];
    }
    return max;
}

// reverse the order of the elements in an array
void reverseArray(int array[], unsigned int size){
    int temp,i = 0;
    for(; i < size/2; i++){
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

// reverse the order of the elements in an array within a range of indices
void reverseSelectedRangeWithinArray(int array[],unsigned int size,unsigned int startRange,unsigned int endRange){
    if (endRange > size || startRange < 0 || startRange > endRange)
        return ;
    int temp,i = 0;
    for(; (startRange + i) < (endRange - startRange)/2; i++){
        temp = array[startRange + i];
        array[startRange + i] = array[endRange - i - 1];
        array[endRange - i - 1] = temp;
    }
}

// find tom jerry pair in array
int findSequence(int arr[],unsigned int size,int tom,int jerry){
    for (unsigned int i = 1;i < size;i++){
        if (arr[i-1] == tom && arr[i] == jerry)
            return i-1;   
    }
    return -1;
}