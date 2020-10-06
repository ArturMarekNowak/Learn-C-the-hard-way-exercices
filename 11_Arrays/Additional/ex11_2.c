#include <stdio.h>

int main (int argc, char *argv[])
{
	int number[4] = { 0 };

	//Only two elements are initialized, all others are '\0'
	//Third task: change name array to another array style
	char *name = { 'a', 'b' };
	
	//Before initialization
	printf("Numbers: %d %d %d %d\n", number[0], number[1], number[2], number[3]);

	printf("Name (seperately): %c %c %c %c %c %c\n", name[0], name[1], name[2], name[3], name[4], name[5]);

	printf("Name: %s\n", name);
	
	//First task: characters to number array 
	number[0] = 'a';
	number[1] = 'b';
	number[2] = 'c';
	number[3] = 'd';

	//Second task: numbers to characters array
	name[0] = 65;
	name[1] = 114;
	name[2] = 116;
	name[3] = 117;
	name[4] = 114;
	name[5] = 0;
	
	//After initialization
	printf("Numbers: %c\n", number[0]);
	printf("Numbers: %c\n", number[1]);
	printf("Numbers: %c\n", number[2]);
	printf("Numbers: %c\n", number[3]);

	printf("Name (seperately): %d %d %d %d %d %d\n", name[0], name[1], name[2], name[3], name[4], name[5]);

	printf("Name: %s\n", name);

	//Another usage
	char *another = "Artur";

	printf("Another: %s\n", another);

	printf("Another (seperately): %c %c %c %c %c %c\n", another[0],	another[1], another[2], another[3], another[4], another[5]);

	return 0;
}
