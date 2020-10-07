#include <stdio.h>

int main (int argc, char *argv[])
{

	//First task part two: move declaration of full_name to beginning of the main
	char full_name[] = { 
		'A', 'r', 't', 'u', 'r', 
		' ', 'M', '.', ' ', 
		'N', 'o', 'w', 'a', 'k'  
	};

	//Second task: change areas[] to areas[10]
	int areas[10] = { 10, 12, 13, 14, 20};
	//Third task: try other methods
	char name[] = 'Artur';
	//First task part one: delete '\0'
	//char full_name[] = { 
	//	'A', 'r', 't', 'u', 'r', 
	//	' ', 'M', '.', ' ', 
	//	'N', 'o', 'w', 'a', 'k'  
	//};

	printf("Size of integer: %ld\n", sizeof(int));
	printf("Size of areas array: %ld\n", sizeof(areas));
	printf("Number of elements in areas: %ld\n", sizeof(areas) / sizeof(int));
	printf("First element is %d, second element is %d\n", areas[0], areas[1]);
	printf("Size of char: %ld\n", sizeof(char));
	printf("Size of array name: %ld\n", sizeof(name));
	printf("Number of elements in name: %ld\n", sizeof(name) / sizeof(char));
	printf("Size of array full_name: %ld\n", sizeof(full_name));
	printf("Number of elements in full_name: %ld\n", sizeof(full_name) / sizeof(char));


	printf("Value of name=\"%s\" and value of full_name=\"%s\"\n", name, full_name);

	return 0;
}	
