#include <stdio.h>

int main (int argc, char *argv[])
{

	if (argc != 2) {
		printf("Error: at leat one argument required\n");
		return 1;
	}

	int i = 0;
	for (i = 0; argv[1][i] != '\0'; i++) {
		//Third task: place in switch type of variable other than expected
		//Fourth task: place in switch uninitialized variable
		int letter;

		//First task: forget about the breaks
		switch (letter) {
			case 'a':
			case 'A':
				printf("%d: 'A'\n", i);
				//break;

			case 'e':
			case 'E':
				printf("%d: 'E'\n", i);
				//break;

			case 'i':
			case 'I':
				printf("%d: 'I'\n", i);
				//break;

			case 'o':
			case 'O':
				printf("%d: 'O'\n", i);
				break;

			case 'u':
			case 'U':
				printf("%d: 'U'\n", i);
				break;

			case 'y':
			case 'Y':
				if (i > 2) {
					//Only sometimes it is going to be Y
					printf("%d: 'Y'\n", i);
				}
				break;

			//Second task: forget about the default
			//default:
				//printf("%d: %c is not a vowel\n", i, letter);

		}
	}

	return 0;
}
