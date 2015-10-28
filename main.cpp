/* Blaise Cannon
 * Knapsack Problem - Sequential
 * 27 September 2015
 *
 * The knapsack problem is an NP-Complete problem in mathematics and the
 * field of computer science. The knapsack problem is the idea that you
 * should take the most valuable items possible while also considering
 * a limited storage capacity. This creates a situation where you want to
 * take items based on the ratio of value to weight, and ignore items that
 * are indeed valuable but with a low ratio when compared to its weight.
 *
 * This problem is computationally hard as the computer must consider each
 * possible combination of items in order to give the best possible
 * solution. Computers will bog down after so many items are added to the
 * data file which the computer is reading from. This program is written
 * in a sequential manner, so the point at which the computer's
 * time-to-completion grows too large will be much quicker than the same
 * problem solved in a parallel manner.
 *
 * =========
 * Resources
 * =========
 *
 * 1. http://www.dreamincode.net/forums/topic/382784-global-array-becoming-null-after-appending-elements/
 */

/* Imports */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Arrays */
char *items[100]; // store item names
int value[100]; // store item value
int weight[100]; // store item weight

/* Iterators */
int k = 0;
int s = 0;

/* Variables */
int ELEMENTS = 0;

/* Constants */
static const int MAX_WEIGHT = 400; // how much the knapsack can hold

void read(void) {
    FILE *data = fopen("data.txt", "r");

    if (data != NULL) {
        char line[256]; // sets max line length to 256
        while (fgets(line, sizeof line, data) != NULL) {
            // WARNINGS: this will break if the correct format of NAME VALUE WEIGHT is not followed

            items[k] = strdup(strtok(line, " "));
            value[k] = atoi(strtok(NULL, " "));
            weight[k] = atoi(strtok(NULL, " "));

            k++;
        }

        fclose(data); // close file
    }

    else {
        fprintf(stderr, "Error reading file, check to make sure it is not locked and that it exists.");
    }

    ELEMENTS = k;
}

void printItems(void) {
    for (s = 0; s < ELEMENTS; s++) {
        printf("Name: %s, Value: %d, Weight: %d\n", items[s], value[s], weight[s]);
    }
}

int main(void) {
    read();
    printItems();

    return 0;
}