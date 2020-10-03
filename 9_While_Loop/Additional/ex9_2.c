#include <stdio.h>

int main(int argc, char *argv[])
{

	int i = 25; 
	while ( i > -1 ) {
		printf("%d", i);
		i--;
	}
	
	printf("\n\n\n");

	i = 1;
	int j = 1, multiplication = 0;
	while ( i < 11)
	{
		while ( j < 11 )
		{
			multiplication = i * j;
			printf("%d ", multiplication);
			j++;
		}
		j = 1;
		i++;
		printf("\n");
	}

	return 0;
}
