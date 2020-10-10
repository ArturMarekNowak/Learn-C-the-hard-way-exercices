#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

//Rewrite this program so that it dosnt use any pointers

#define NAMESIZE 1024

struct Person {
	char name[NAMESIZE];
	int age;
	int height;
	int weight;
};

struct Person Person_create(char name[], int age, int height, int weight)
{
	struct Person who;
	assert(strlen(name) < NAMESIZE - 1);

	strcpy(who.name, name);
	who.age = age; 
	who.height = height;
	who.weight = weight;

	return who;
}

/*
void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}
*/

void Person_print(struct Person who)
{
	printf("Person: %s\n", who.name);
	printf("\tAge: %d\n", who.age);
	printf("\tHeight: %d\n", who.height);
	printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
	struct Person joe = Person_create("Joe Alex", 32, 174, 60);

	struct Person frank = Person_create("Frank Blank", 20, 185, 95);

	printf("Joe's address is: %p\n", joe);

	Person_print(joe);
	
	printf("Frank's address is: %p\n", frank);

	Person_print(frank);

	joe.age += 20;
	joe.height -= 5;
	joe.weight += 11;
	Person_print(joe);

	frank.age += 5;
	frank.height -= 16;
	frank.weight += 1;
	Person_print(frank);

	//Person_destroy(joe);
	//Person_destroy(frank);

	return 0;

}

