#include <stdio.h>

int main (int argc, char *argv[])
{
	int i = 0, j = 20, k = 5;
	
	
	//We create our own char array
	//Second task: add NULL
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas",
		NULL, NULL, "Alaska"
	};

	//Going thorugh all char arrays 
	//We skip first argument cause it is an ./ex13
	//Third task: assign states to argv and vice versa
	for ( i = 1; i < argc; i++)
	{
		states[i] = argv[i];

		printf("Argument: %d: %s\n", i, argv[i]);
	}


	int num_states = 10;
	
	//First task: find out usage of , in loop 
	for ( i = 0, j = 20, k = 5; i < num_states; i++, j--)
	{
		printf("State %d: %s, j: %d, k: %d\n", i, states[i], j, k);
	}

	return 0;
}
