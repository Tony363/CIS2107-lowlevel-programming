#include <stdio.h>

//24. What will be the output of the C program?

int main(void) {
  int age = 5, tom = 0, jerry = 0;
  int* aPtr = &age;
  tom = (*aPtr)++;              // post associativity  is left to right 
  printf("\n%d", age);          // by the way post is higher than pre
  printf("\n%d", tom);

  age = 55;
  jerry = ++(*aPtr);            // pre associativity  is right to left
  printf("\n%d", age);
  printf("\n%d", jerry);
  return 0;
}






//23. What will be the output of the C program?

#include<stdio.h>
int main()
{
	printf("%d\n", sizeof(void *));
	printf("%d\n", sizeof(void));
	return 0;
}

/*
Answer?
8
1

Why? 
size of pointer depends on the machine architecture.
size of void data type (for organizational purposes)is always 1.

*/


// 22. What will be the output of the C program?

#include<stdio.h>
int main()
{
	char *ptr = NULL;
	char string[] = "learn C from 2107";
	ptr = string;
	ptr += 6;
	printf("%s", ptr);				
	return 0;
}

/*
Answer?
C from 2107

Why?
The pointer moves the 7th place of the array (index 6) and print the rest of it.

*/


//20. What will be the output of the C program?

#include<stdio.h>
int main(){
	int tom = 0, jerry = 0, spike = 0;
	char *tomPtr = NULL;
	int *jerryPtr = NULL;
	double *spikePtr = NULL;
	
	tom = (int)(tomPtr + 1);
	jerry = (int)(jerryPtr + 1);
	spike = (int)(spikePtr + 1);
	
	printf("%d %d  %d",tom, jerry, spike);
	return 0;
}

/*
Answer? 
1	4	8
The number 1 here repsents the size of the data type in memory.
*/

// 19. What will be the output of the C program?

#include<stdio.h>
int main(){
	int tom = 1992;
	int *jerry;
	int **spike;
	jerry = &tom;
	spike = &jerry;
	printf("%u %u %u ",spike,*spike,**spike);
	return 0;
}

/*
Answer?
Address of jerry	address of tom	value of tom
*/



// 16. What will be the output of the C program?

#include<stdio.h>
int main(){
	int *ptr;
	*ptr = 5;
	printf("%d" , *ptr);
	return 0;
}

/*

Answer?
Segmeantation fault.

Pointers must point to memory locations.
(Unless of course the pointer is null or invalid, but in that case you cannot write through it anyway).
The expression 5 doesn't indicate a memory location. 
There isn't some memory sitting out there with 5 in it waiting to be pointed at. 
We say that 5 is a value (belongs to the right side) for this reason.
*/


//9. What will be the output of the C program?

#include<stdio.h>
#include<string.h>
int main(){
	char tom = 30, jerry = 40;
	char *aPtr = &tom, *bPtr = &jerry;
	printf("%d", aPtr - bPtr);
	return 0;
}

/*Answer? 
It depends. Undefined behavior.

Taking the difference of two pointers is defined by the C Standard only if 
both pointers point to the same (array) object (or one behind), 
so the OP's code invokes undefined behaviour. 

The result could be anything.

*/

//7. What will be the output of the C program?

#include<stdio.h>
int main()
{
	char *ptr = "2beornottobe";
	printf("%c\n",*&*ptr);			// try %d. you will get 50 the decimal value of 2 in ASCII table.
	return 0;
}

/*
Answer? 
2

Why?
Read from right to left, & and *  always cancel each other. 
So: *&*aPtr = *aPtr, that reads a single character with %c.

*/

//6. What will be the output of the C program?

#include<stdio.h>
int main(void){
	char *aPtr = "What a journey!";
	printf("%s", aPtr+7);
	return 0;
}

/*
Answer? 
journey.

Why?
ptr+7 tells the compiler to start reading from 7th place of a string "What a journey!".
*/

//5. What will be the output of the C program?

#include<stdio.h>
#include<string.h>
int main(){
	char *ptr = "hello";
	char array[22];
	*ptr = "world";
	printf("\n%s %s",ptr, array);
	return 0;
}

/*
Answer? 
Compilation Time error.

Why?
ptr is a pointer variable of character data type, 
string "world" can be set to the pointer variable ptr only at the initializing time.
*/

//4. What will be the output of the C program?

#include<stdio.h>
#include<string.h>
int main (void) {
	char *aPtr = "baby shark";
	char songTitle[6];						// Question: try 5 instead of 6, and see what happens?
	strcpy(songTitle, "dance");
	printf("\n%s %s",aPtr, songTitle);
	return 0;
}

/*
Answer?
baby shark dance

Why?
Set the pointer to a char string "baby shark" and 
set a normal variable to copy the string "dance" using the inbuilt function strcpy.
strcpy runs as to copy to destiantion from source. i.e., to songTitle from "dance". 
*/



//2. What will be the output of the C program?

#include<stdio.h>
int main(){
	int tom = 3;
	int *jerry;
	int **spike;
	jerry = &tom;
	spike = &jerry;
	spike++;
	printf("%d ",**spike);
	return 0;
}

/*
Answer?
some garbage value.

Why? 
When the address of a pointer variable spike is incremented by 1, that means it points to
some garbage value which is not the address of any other variable printed at run-time. 

*/

//1. What will be the output of the C program?

#include<stdio.h>
int main(){
	int droopy = 128;
	char *aPtr;
	aPtr = (char *)&droopy;
	printf("%d ",*aPtr);
	return 0;
}

/*

Answer?

-128


Why?
First, a variable droppy holds the value 128 of integer datatypes, we type-casted it to char datatypes 
using a pointer variable. A value 128 is outside the char range( -128 to 127), thus we loop through its range.

For Example
128 = -128
129 = -127
130 = -126
131 = -125

*/






