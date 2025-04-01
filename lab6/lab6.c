#include <stdio.h>
#include <math.h>


// function scans a line of DS4rd data and returns true if square is pressed
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_X, int* Button_S, int* Button_C) {
    return scanf("%d %lf %lf %lf %d %d %d %d", time, g_x, g_y, g_z, Button_T, Button_X, Button_S, Button_C) == 8;
}

// PRE: -1.0 <= x_mag <= 1.0
// Computes the roll of the DS4 in radians
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag) {
    if (x_mag < -1.0) x_mag = -1.0;  // Clamping values
    if (x_mag > 1.0) x_mag = 1.0;
    return asin(x_mag);
}

// Computes the pitch of the DS4 in radians

double pitch(double y_mag) {
    if (y_mag < -1.0) y_mag = -1.0;
    if (y_mag > 1.0) y_mag = 1.0;
    return asin(y_mag);
}

// Scales the roll value to fit on the screen (-39 to 39)

int scaleRadsForScreen(double rad) {
    return (int)((rad / (M_PI / 2)) * 39);
}

// Prints the character 'use' num times
void print_chars(int num, char use) {
    for (int i = 0; i < num; i++) {
        printf("%c", use);
    }
    printf("\n"); // Move to the next line
}

// Uses print_chars to graph a number from -39 to 39 on the screen
// The graph is centered at column 40 because said in instuctions
void graph_line(int number) {
    if (number == 0) {
        // Print '0' at column 40
        for (int i = 0; i < 40; i++) printf(" ");
        printf("0\n");
    } else if (number > 0) {
        // Print '0' at column 40, then 'r' to the right
        for (int i = 0; i < 40; i++) printf(" ");
        printf("0");
        print_chars(number, 'r');
    } else {
        // Print 'l' to the left, then '0' at column 40
        print_chars(40 + number, ' ');
        print_chars(-number, 'l');
        printf("0\n");
    }
}

int main() {
    double g_x, g_y, g_z;
    int time, Button_T, Button_X, Button_S, Button_C;
    int graphing_roll = 1; // Start with roll mode

    while (1) {
        if (!read_line(&g_x, &g_y, &g_z, &time, &Button_T, &Button_X, &Button_S, &Button_C)) {
            continue; // Ignore invalid input
        }

        if (Button_S) break; // Exit if Square button is pressed
        if (Button_T) graphing_roll = 1; // Switch to roll if Triangle is pressed
        if (Button_X) graphing_roll = 0; // Switch to pitch if X is pressed

        double rad_value = graphing_roll ? roll(g_x) : pitch(g_y);
        int screen_value = scaleRadsForScreen(rad_value);

        graph_line(screen_value);
    }

    return 0;
}
