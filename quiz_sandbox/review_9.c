#include<stdio.h>
#include<string.h>

int main(){
	char tom = 30, jerry = 40;
	char *aPtr = &tom, *bPtr = &jerry;
	printf("%ld %d %d %d %d", aPtr - bPtr,*aPtr,(int)bPtr,tom,jerry);
	return 0;
}
