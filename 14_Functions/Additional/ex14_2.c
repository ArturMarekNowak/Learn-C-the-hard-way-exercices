#include <stdio.h>
#include <ctype.h>

//Second task: dont depend on '\0' but find out the length
#include <string.h>

//Forward declarations
//int can_print_it(char ch);
void print_letters(char arg[], int arg_length);

void print_arguments(int argc, char *argv[])
{
	int i = 0; 
	//length = 0;

	for (i = 0; i < argc; i++) {
		//length = strlen(argv[i]);
		print_letters(argv[i], strlen(argv[i]));
	}
}

void print_letters(char arg[], int arg_length)
{
	int i = 0;

	for (i = 0; i != arg_length; i++) { 
		char ch = arg[i];
		
		//Task three: print only digits
		if (isdigit(ch) || isblank(ch)) {
			printf("'%c' == %d ", ch, ch);
		}
	}
	printf("\n");
}

//First task: we dont need can_print_it
//int can_print_it(char ch)
//{
//	return isalpha(ch) || isblank(ch);
//}

int main (int argc, char *argv[])
{
	print_arguments(argc, argv);
	return 0;
}


