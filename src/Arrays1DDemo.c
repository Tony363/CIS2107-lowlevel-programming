#include <stdio.h>
#include <stdlib.h>

// function prototypes
void fillArray(int arr[],unsigned int size,int rand_min,int rand_max);
int findWithRange(int array[],unsigned int size,unsigned int lowSelectedRange,unsigned int highSelectedRange);
void reverseArray(int array[], int size);
void reverseSelectedRangeWithinArray(int array[],int size,int startRange,int endRange);
int findSequence(int arr[],int size,int tom,int jerry);

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
    printf("sequence: %d\n",findSequence(arr,10,0,10));
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
void reverseArray(int array[], int size){
    int temp,i = 0;
    for(; i < size/2; i++){
        temp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = temp;
    }
}

// reverse the order of the elements in an array within a range of indices
void reverseSelectedRangeWithinArray(int array[],int size,int startRange,int endRange){
    if (endRange > size || startRange < 0 || startRange > endRange)
        return ;
    int temp,i = 0;
    for(; (startRange + i) < (endRange - startRange)/2; i++){
        temp = array[startRange + i];
        array[startRange + i] = array[endRange - i - 1];
        array[endRange - i - 1] = temp;
    }
}

// ??????
int findSequence(int arr[],int size,int tom,int jerry){
    int tom_found,jerry_found = -1;
    for (int i = 0;i < size;i++){
        if (tom_found && jerry_found)
            return tom_found;
        if (!tom && arr[i] == tom)
            tom_found = i;
        if (!jerry && arr[i] == jerry)
            jerry_found = i;
    }
    return -1;
}