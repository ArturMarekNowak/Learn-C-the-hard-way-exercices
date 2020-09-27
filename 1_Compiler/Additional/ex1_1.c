#include <stdio.h>

int main(int argc, int *argv[])
{
	int distance = 100, number_1 = 10, number_2 = 20, day = 11, hour = 13, min = 30;
        char *weekday = "Friday", *month = "July";

        fprintf(stdout, "%s, %s %d, %.2d:%.2d\n", weekday, month, day, hour, min);
	printf("%2$*1$d\n", number_1, number_2);
	printf("%2$*1$d\n", number_2, number_1);
	printf("You are %d kilometers away\n", distance);
	return 0;
}

