#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;
static int THE_AGE = 23;

int get_age()
{
	return THE_AGE;
}

void set_age(int age)
{
	THE_AGE = age;
}

double * update_ratio(double new_ratio)
{
	//Getting ratio variable via pointer
	static double ratio = 1.0;
	double *ratio_ptr = &ratio;


	//double old_ratio = ratio;
	//ratio = new_ratio;

	return ratio_ptr;
}

void print_size()
{
	log_info("I think size is: %d", THE_SIZE);
}


