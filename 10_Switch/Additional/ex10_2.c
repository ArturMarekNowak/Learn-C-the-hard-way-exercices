#include <stdio.h>

int main (int argc, char *argv[])
{

	if (argc < 2) {
		printf("Error: at leat one argument required\n");
		return 1;
	}

	int i = 0, j = 1;
	for (j = 1; j < argc; j++) {
		for (i = 0; argv[j][i] != '\0'; i++) {
			char letter = argv[j][i];

			switch (letter) {
				case 'a':
				case 'A':
					printf("%d: 'A'\n", i);
					break;

				case 'e':
				case 'E':
					printf("%d: 'E'\n", i);
					break;

				case 'i':
				case 'I':
					printf("%d: 'I'\n", i);
					break;

				case 'o':
				case 'O':
					printf("%d: 'O'\n", i);
					break;

				case 'u':
				case 'U':
					printf("%d: 'U'\n", i);
					break;
			
				//Works properly for Y and is not working with any other vowel
				if (i > 2) {
					case 'y':
					case 'Y':
					//Only sometimes it is going to be Y
					printf("%d: 'Y'\n", i);
				}
				break;

				default:
					printf("%d: %c is not a vowel\n", i, letter);

			}
		}
	}

	return 0;
}
