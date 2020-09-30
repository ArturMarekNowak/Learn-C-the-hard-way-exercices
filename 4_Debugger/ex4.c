#include <stdio.h>

int main(int argc, char *argv[])
{
	int age = 10;
	int height = 183;
	
	int *breaking_code = NULL;

	printf("I am %d years old\n", age);
	printf("I am %d cm high\n", height);
	
	for(int i = 0; i < 100000; i++)
	{
		printf("%c", breaking_code[i]);
	}

	return 0;

}
