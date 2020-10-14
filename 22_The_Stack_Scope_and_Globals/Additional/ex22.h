#ifndef _ex22_h
#define _ex22_h

//Variable THE_SIZE becomes visible in other .c files
extern int THE_SIZE;

//Gets and sets an internal static variable in ex22.c
int get_age();
void set_age(int age);

//Updates a static variable that's inside update_ratio
double update_ratio(double ratio);
void print_size();

#endif

