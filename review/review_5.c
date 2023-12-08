
#include<stdio.h>
#include<string.h>

int main(){
	char *ptr = "hello";
    char *ptr1 = "world";
	// char array[22];
    // strcpy(ptr,ptr1);
	ptr = ptr1;
	printf("\n%s ",ptr);
	return 0;
}
