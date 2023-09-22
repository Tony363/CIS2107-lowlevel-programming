#include <stdio.h>
#include <stdlib.h>

/*
Tony Siu
9/14/2023
CIS 2107
Lab 4: Arrays
*/


// function prototypes
void print_array(int arr[],unsigned int size);
void fillArray(int arr[],unsigned int size,int rand_min,int rand_max);
void reverseArray(int array[], unsigned int size);
void reverseSelectedRangeWithinArray(int array[],unsigned int size,unsigned int startRange,unsigned int endRange);
int findWithRange(int array[],unsigned int size,unsigned int lowSelectedRange,unsigned int highSelectedRange);
int findSequence(int arr[],unsigned int size,int tom,int jerry);


// gcc -o executables/arrays -g src/Arrays1DDemo.c
int main(){
    unsigned int size = 40;
    int arr[40] = {0};

    fillArray(arr,size,0,size);
    puts("Output random filled array");
    print_array(arr,size);
    
    printf("max between index %d - %d: %d\n\n",5,10,findWithRange(arr,size,5,10));
    
    reverseArray(arr,size);
    puts("Output array after reversing");
    print_array(arr,size);
    
    puts("Output reversing selected range within array");
    reverseSelectedRangeWithinArray(arr,size,0,5);
    print_array(arr,size);
    
    printf("No (%d,%d) tom jerry pair %d\n",0,10,findSequence(arr,size,0,10));
    printf("Tom jerry pair (%d,%d) from index %d\n",arr[4],arr[5],findSequence(arr,size,arr[4],arr[5]));
    return 0;
}

// function to print array
void print_array(int arr[],unsigned int size){
    if (!size){
        puts("[]");
        return;
    }
    printf("%c\n",'[');
    for(unsigned int i = 0; i < size; i++){
        if (!(i % 10) && i != 0) puts("");
        printf("%4d,",arr[i]);
    }
    puts("\n]\n");
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
    if (size < 2)
        return -1;
    for (unsigned int i = 1;i < size;i++){
        if (arr[i-1] == tom && arr[i] == jerry)
            return i-1;   
    }
    return -1;
}