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
	for ( i = 0; i < count; i++) {
		printf("%s is %d years old\n", names[i], ages[i]);
	}
	
	printf("------------\n");

	//Pointer declared so that they point to the beginning of arrays
	int *cur_age = ages;
	char **cur_name = names;
	
	//Second way: pointers
	for ( i = 0; i < count; i++) {
		printf("%s is %d years old\n", *(cur_name + i), *(cur_age + i));
	}

	printf("------------\n");

	//Third way: using pointers as arrays
	for ( i = 0; i < count; i++) {
		printf("%s is %d years old\n", cur_name[i], cur_age[i]);
	}

	printf("------------\n");

	//Fourth way: pointers but complicated way too much 
	for ( cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
		//Just my curiosity
		//printf("cur_age: %d, ages: %d, cur_age - ages: %d, count: %d\n", cur_age, ages, cur_age - ages, count);
		printf("%s is %d years old\n", *cur_name, *cur_age);
	}

	return 0;
}



