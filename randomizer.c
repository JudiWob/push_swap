#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 100
#define MIN_NUM -3000
#define MAX_NUM 4000

// Function to check if a number is already in the arrxy
int	is_unique(int *arr, int num, int count)
{
	for (int i = 0; i < count; i++)
	{
		if (arr[i] == num)
		{
			return (0); // Number already exists
		}
	}
	return (1); // Number is unique
}

int	main(void)
{
	FILE	*file;
	int		numbers[NUM_COUNT];
	int		count;
	int		rand_num;

	file = fopen("number.txt", "w");
	if (file == NULL)
	{
		printf("Error opening file!\n");
		return (1);
	}
	count = 0;
	// Seed the random number generator
	srand(time(NULL));
	while (count < NUM_COUNT)
	{
		rand_num = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;
		if (is_unique(numbers, rand_num, count))
		{
			numbers[count] = rand_num;
			count++;
		}
	}
	// Write the numbers to the file
	for (int i = 0; i < NUM_COUNT; i++)
	{
		fprintf(file, "%d ", numbers[i]);
	}
	fclose(file);
	printf("500 unique random numbers have been written to number.txt\n");
	return (0);
}

//./pushswap  88 675 2 0 999 -08643 56 78 -456 4 -666 -4 777 -543 9 -23 99 22
//./pushswap 1 -762 3 -1 2 5 999 -1111 63  -6574  30  2222 65 -222 75645
// ./push_swap 871 -1270 -328 417 978 -98 -1078 3513 3148 2717 658 2543 -1525 2637 -492 -1564 3614 947 -605 3243 1373 -2799 3528 2435 -898 -53 -2337 3755 1716 1088 -2494 -1462 713 3839 3714 3975 3697 -1650 3138 3495 -2093 -554 -1345 2500 -1170 387 3830 -1385 1079 3114 3100 2996 1051 -66 -1645 3494 813 2672 1970 -1403 -177 -619 211 -1298 909 -283 542 2850 2874 491 1905 2799 2572 1039 -1122 3886 3443 -2807 2396 -1458 3660 2104 -2977 1260 859 -1994 -2774 1926 -2149 2318 -519 -203 -371 -22 800 -1091 -2865 52 -319 32

// ; ./push_swap $ARG | ./checker_linux $ARG