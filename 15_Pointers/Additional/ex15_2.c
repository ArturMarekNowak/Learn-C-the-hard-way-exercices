#include <stdio.h>

//Print out using functions
void first_loop(char ** ptr_argv, int argc);
void second_loop(int * cur_age, char ** cur_name, int count);
void third_loop(int * cur_age, char ** cur_name, int count);
void fourth_loop(int * cur_age, char ** cur_name, char ** names, int * ages, int count);

int main (int argc, char *argv[])
{
	//Task six: prints pointer addresses
	//Task seven: all loops change to while
	//Task four: take care of arguments
	char **ptr_argv = argv;

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
	//for (i = 0; i < count; i++) {
	//	printf("%s is %d years old\n", names[i], ages[i]);
	//}
	
	while (i < count) {

		printf("%s is %d years old\n", names[i], ages[i]);
		i++;

	}

	printf("------------\n");

	//Pointer declared so that they point to the beginning of arrays
	int *cur_age = ages;
	char **cur_name = names;
	
	first_loop(ptr_argv, argc);

	second_loop(cur_age, cur_name, count);

	third_loop(cur_age, cur_name, count);

	fourth_loop(cur_age, cur_name, names, ages, count);

	return 0;
}


void first_loop(char ** ptr_argv, int argc) {
	
	int i = 1;

	//Task four loop
	//for ( i = 1; i < argc; i++) {
	//	printf("Argument %d: %s, used ptr addr: %p \n", i, *(ptr_argv + i), (ptr_argv + i));
	//}
	while (i < argc) {

		printf("Argument %d: %s, used ptr addr: %p \n", i, *(ptr_argv + i), (ptr_argv + i));
		i++;
	}

	printf("------------\n");
}





void second_loop(int * cur_age, char ** cur_name, int count) {
	
	int i = 0;

	//Second way: pointers
	//for ( i = 0; i < count; i++) {
	//	printf("%s is %d years old, used ptr addr: %p, %p \n", *(cur_name + i), *(cur_age + i), (cur_name + i), (cur_age + i));
	//}
	
	while (i < count) {
		printf("%s is %d years old, used ptr addr: %p, %p \n", *(cur_name + i), *(cur_age + i), (cur_name + i), (cur_age + i));
		i++;
	}

	printf("------------\n");

}




void third_loop(int * cur_age, char ** cur_name, int count) {

	int i = 0;
	
	//Third way: using pointers as arrays
	//for ( i = 0; i < count; i++) {
	//	printf("%s is %d years old, used ptr addr: %p, %p \n", cur_name[i], cur_age[i], &cur_name[i], &cur_age[i]);
	//}

	while (i < count) {
		printf("%s is %d years old, used ptr addr: %p, %p \n", cur_name[i], cur_age[i], &cur_name[i], &cur_age[i]);
		i++;
	}

	printf("------------\n");

}




void fourth_loop(int * cur_age, char ** cur_name, char ** names, int * ages, int count) {
	
	//Fourth way: pointers but complicated way too much 
	//for ( cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++) {
		//Just my curiosity
		//printf("cur_age: %d, ages: %d, cur_age - ages: %d, count: %d\n", cur_age, ages, cur_age - ages, count);
	//	printf("%s is %d years old, used ptr addr: %p, %p \n", *cur_name, *cur_age, cur_name, cur_age);
	//}
	cur_name = names;
	cur_age = ages;
	while ((cur_age - ages) < count) {

		printf("%s is %d years old, used ptr addr: %p, %p \n", *cur_name, *cur_age, cur_name, cur_age);
		cur_name++;
		cur_age++;
	}
}

