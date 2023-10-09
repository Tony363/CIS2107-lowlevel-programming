#include<stdio.h>
#include <stdlib.h>

int sumEvenNumbers(int *arr,size_t len){
    int sum = 0;
    for (size_t i=0;i<len;i++)
        if (!(i % 2))
            sum += arr[i];
    return sum;
}

int main(){
    // int numbers[][] = {{1,2},{3,4}};
    // int i,j;
    // for (i=0;i<=1;i++)
    //     for (j=0;j<=1;j++)
    //         printf("%d\n",numbers[i][j]);
    // int shifts[5] = {1};
    // for (size_t i = 0; i< 5;i++)
    //     printf("%d\n",shifts[i]);
    // float seasons[] = {1,2,3,4};
    // printf("%lu\n",sizeof(seasons)/sizeof(seasons[0]));
    double NFLTeams[32] = {0};
    NFLTeams[33] = 2020;
    // NFLTeams[34] = 999;
    NFLTeams[50] = 777;
    for (size_t i = 0; i<=50;i++)
        printf("%p %ld %f\n",&NFLTeams[i],i,NFLTeams[i]);
    printf("%ld\n",sizeof(NFLTeams));
    // for (size_t i = 0; i<=50;i++)
    //     printf("%d\n",NFLTeams[i]);

    // int arr[5] = {1,2,3,4,5};
    // printf("%d\n",sumEvenNumbers(arr,5));
    return 0;
}