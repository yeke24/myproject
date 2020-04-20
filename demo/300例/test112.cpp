
#include<stdio.h>

#include<stdlib.h>

 

void func1()

{

	printf("The process is done...\n");

}

void func2()

{

	printf("Clean up the processing\n");

}

void func3()

{

	printf("Exit sucessful..\n");

}

int main()

{

	atexit(func1);

	atexit(func2);

	atexit(func3);

	exit(0);

}

