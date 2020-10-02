#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int i = 1, reverse = 0;

	if (argc == 1) {
		printf("No arguments\n");
	} else if (argc > 1 && argc < 10) {
		printf("The arguments are:\n");

		for(i = 1; i < argc; i++) {
			if (!strcmp(argv[i],"-r")) {
				reverse = 1;
			}
		}

		if (reverse) {
			for (i = argc - 1; i > 0; i--) {
				printf("%s ", argv[i]);
			}	
		} else {
			for (i = 1; i < argc; i++) {
				printf("%s ", argv[i]);
			}
		}	
		printf("\n");


	} else {
		printf("Too many arguments\n");
	}

	return 0;
}
