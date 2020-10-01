#include <stdio.h> 

int main(int argc, char *argv[])
{
	int distance = 100;
	float power = 2.345f;
	double super_power = 56789.4532;
	char initial = 'M';
	char first_name[] = "Artur";
	char last_name[] = "Nowak";
	
	printf("You are %d kilometers away\n", distance);
	printf("You have %f power levels\n", power);
	printf("You have %f levels of super power\n", super_power);
	printf("Initial letter of second name is %c\n", initial);
	printf("My first name is %s\n", first_name);
	printf("My last name is %s\n", last_name);
	printf("My full name is %s %c. %s.\n", first_name, initial, last_name);

	int bugs = 100;
	double bug_rate = 1.2;

	printf("You have %d bugs on imaginary level %f\n", bugs, bug_rate);

	long universe_of_defects = 1L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L + 1; //Maximum 64 bits or 8 bytes
	printf("Whole signed universe consists of %ld defects\n", universe_of_defects);

	unsigned long unsigned_universe_of_defects = 2L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L * 1024L + 1; //Maximum at double of signed
	printf("Whole unsgined universe consists of %ld defects\n", unsigned_universe_of_defects);

	double expected_bugs = bugs * bug_rate;
	printf("You should have %f errors\n", expected_bugs);

	double part_of_universe = expected_bugs / universe_of_defects;
	printf("That is only %e defects in universe\n", part_of_universe);

	//That is pointless, just demo of something new
	char nul_byte = '\0';
	int care_percentage = bugs * nul_byte; 
	printf("You should care about this in %d%%\n", care_percentage);

	return 0;
}

