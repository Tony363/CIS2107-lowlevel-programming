#include <stdio.h>

// can type cast pointers to values
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
