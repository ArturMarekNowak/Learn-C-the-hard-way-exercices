#include <stdio.h>

int main (int argc, char *argv[])
{
	int number[4] = { 0 };

	//Only two elements are initialized, all others are '\0'
	char name[6] = { 'a', 'b' };
	
	//Before initialization
	printf("Numbers: %d %d %d %d\n", number[0], number[1], number[2], number[3]);

	printf("Name (seperately): %c %c %c %c %c %c\n", name[0], name[1], name[2], name[3], name[4], name[5]);

	printf("Name: %s\n", name);

	number[0] = 1;
	number[1] = 2;
	number[2] = 3;
	number[3] = 4;

	name[0] = 'A';
	name[1] = 'r';
	name[2] = 't';
	name[3] = 'u';
	name[4] = 'r';
	name[5] = '\0';
	
	//After initialization
	printf("Numbers: %d %d %d %d\n", number[0], number[1], number[2], number[3]);

	printf("Name (seperately): %c %c %c %c %c %c\n", name[0], name[1], name[2], name[3], name[4], name[5]);

	printf("Name: %s\n", name);

	//Another usage
	char *another = "Artur";

	printf("Another: %s\n", another);

	printf("Another (seperately): %c %c %c %c %c %c\n", another[0],	another[1], another[2], another[3], another[4], another[5]);

	return 0;
}
