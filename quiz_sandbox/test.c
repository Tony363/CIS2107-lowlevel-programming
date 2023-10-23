#include <stdio.h>

int main(){
    // int x,y = 0;
    // int * const ptr = &x;
    // *ptr = 7;
    // // ptr = &y;
    // int x = 20,*y,*z;
    // y = &x;
    // z = y;
    // printf("x = %d, y= %p, z= %p \n",x,y,z);
    // *y++;
    // printf("x = %d, y= %p, z= %p \n",x,y,z);
    // *z++;
    // x++;
    // printf("x = %d, y= %p, z= %p \n",x,y,z);
    // int grades[5] = {95,90,100,82,92};
    // int *iPtr = grades;
    // printf("%d\t%d\t%p\t%p\n",*iPtr,grades[0],grades,iPtr);
    // int arr[] = {1,2,3};
    // int *ptr = arr;
    // ptr += 3;
    // printf("%d",*ptr);
    int b = 2, i = 0;
    int a[4] = {0,1,2,3};
    printf("%d %d %d\n",++a[i++] * b++,i,b);
    return 0;
}