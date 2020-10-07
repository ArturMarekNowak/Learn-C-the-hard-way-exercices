#include <stdio.h>

int main (int argc, char *argv[])
{
	int i = 0;

	//Going thorugh all char arrays 
	//We skip first argument cause it is an ./ex13
	//First task: initialize i with 0
	for ( i = 0; i < argc; i++)
	{
		printf("Argument: %d: %s\n", i, argv[i]);
	}

	//We create our own char array
	//Second task: increase num_states
	char *states[] = {
		"California", "Oregon",
		"Washington", "Texas"
	};

	int num_states = 10;

	for ( i = 0; i < num_states; i++)
	{
		printf("State %d: %s\n", i, states[i]);
	}

	return 0;
}
