/* 185 Lab 3 Template */

#include <stdio.h>
#include <math.h>

/* Put your function prototypes here */
int numButtons(int triangle, int x, int square, int circle);
int main(void) {
    /* DO NOT MODIFY THESE VARIABLE DECLARATIONS */
    int triangle, x, square, circle;
     


    /* This while loop makes your code repeat. Don't get rid of it. */
    while (1) {
        scanf("%d,%d,%d,%d", &triangle, &x, &square, &circle);

        // Call the function to count pressed buttons
        int pressed = count_buttons(triangle, x, square, circle);

        // Print the number of buttons pressed
        printf("Buttons pressed: %d\n", pressed);

        // Flush the output buffer
        fflush(stdout);
    }

    
    

return 0;
}


/* Put your functions here */

int numButtons(int triangle, int x, int square, int circle) {
    int count = 0;


    if (triangle) count++;
    if (circle) count++;
    if (x) count++;
    if (square) count++;

    return count;
}