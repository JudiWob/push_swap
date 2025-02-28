#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 299
#define MIN_NUM -3000
#define MAX_NUM 4000

// Function to check if a number is already in the array
int is_unique(int *arr, int num, int count) {
    for (int i = 0; i < count; i++) {
        if (arr[i] == num) {
            return 0; // Number already exists
        }
    }
    return 1; // Number is unique
}

int main() 
{
    FILE *file = fopen("number.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    int numbers[NUM_COUNT];
    int count = 0;

    // Seed the random number generator
    srand(time(NULL));

    while (count < NUM_COUNT) {
        int rand_num = (rand() % (MAX_NUM - MIN_NUM + 1)) + MIN_NUM;

        if (is_unique(numbers, rand_num, count)) {
            numbers[count] = rand_num;
            count++;
        }
    }

    // Write the numbers to the file
    for (int i = 0; i < NUM_COUNT; i++) {
        fprintf(file, "%d ", numbers[i]);
    }

    fclose(file);
    printf("500 unique random numbers have been written to number.txt\n");

    return 0;
}