#include <stdio.h>

int main (int argc, char *argv[])
{
	//Two arrays
	int ages[] = { 25, 47, 12, 89, 5 };
	char *names[] = {
		"Alan", "Franek",
		"Mariusz", "Janek", "Ludwik"
	};

	//Determination of size
	int count = sizeof(ages) / sizeof(int);
	int i = 0;

	//First way: loop
	//Task three: make loops to go from last to first element
	for ( i = count - 1; i > -1; i--) {
		printf("%s is %d years old\n", names[i], ages[i]);
	}
	
	printf("------------\n");

	//Pointer declared so that they point to the beginning of arrays
	//Task one: make *cur_age to point at name
	//int *cur_age = (int *) names;
	int *cur_age = ages;
	char **cur_name = names;
	
	//Second way: pointers
	for ( i = count - 1; i > -1; i--) {
		printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
	}

	printf("------------\n");

	//Third way: using pointers as arrays
	for ( i = count - 1; i > -1; i--) {
		printf("%s is %d years old\n", cur_name[i], cur_age[i]);
	}

	printf("------------\n");

	//Fourth way: pointers but complicated way too much 
	//Task two: mess with math, addition of pointers not allowed!
	for ( cur_name = names + count - 1, cur_age = ages + count - 1; (cur_age - ages) > -1; cur_name--, cur_age--) {
		//Just my curiosity
		//printf("cur_age: %d, ages: %d, cur_age - ages: %d, count: %d\n", cur_age, ages, cur_age - ages, count);
		printf("%s is %d years old\n", *cur_name, *cur_age);
	}

	return 0;
}



