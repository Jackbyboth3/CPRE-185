#include <stdio.h>
#include <math.h>


// function scans a line of DS4rd data and returns true if square is pressed
int read_line(double* g_x, double* g_y, double* g_z, int* time, int* Button_T, int* Button_C, int* Button_X, int* Button_S) {
    scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d", time, g_x, g_y, g_z, Button_T, Button_C, Button_X, Button_S);
    if(*Button_S == 1) {
        return 1; 
    }
    else {
        return 0; // otherwise, return false
    }
}

// Computes the roll of the DS4 in radians
double roll(double x_mag) {
    if (x_mag < -1.0) x_mag = -1.0;  
    if (x_mag > 1.0) x_mag = 1.0;
    return asin(x_mag);
}

// Computes the pitch of the DS4 in radians with asin from math

double pitch(double y_mag) {
    if (y_mag < -1.0) y_mag = -1.0;
    if (y_mag > 1.0) y_mag = 1.0;
    return asin(y_mag);
}

// roll value fit on the screen with because 40 (-39 to 39)

int scaleRadsForScreen(double rad) {
    return (int)((rad / (M_PI / 2)) * 39);
}

// Prints the char use num times
void print_chars(int num, char use) {
    for (int i = 0; i < num; i++) {
        printf("%c", use);
    }
    printf("\n"); 
}

// Uses print_chars to graph a number from -39 to 39 on the screen
// The graph is centered at column 40 because said in instuctions
void graph_line(int number) {
    if (number == 0) {
        for (int i = 0; i < 40; i++) printf(" ");
    } else if (number > 0) {
        for (int i = 0; i < 40; i++) printf(" ");
        print_chars(number, 'r');
    } else {
        // Print 'l' to the left
        print_chars(40 + number, ' ');
        print_chars(-number, 'l');
        
    }
}

int main() {
    double g_x, g_y, g_z;
    int time, Button_T, Button_X, Button_S, Button_C;
    double roll_rad, pitch_rad; // value of the roll measured in radians
    int scaled_value; // value of the roll adjusted to fit screen display
    int graphing_roll =1;

    do {
        read_line(&g_x, &g_y, &g_z, &time, &Button_T, &Button_C, &Button_X, &Button_S); // read line of input
        

        
        // calculate roll and pitch. Use the buttons to set the condition for roll and pitch
        roll_rad = roll(g_x);
        pitch_rad = pitch(g_y)
        
        
        if(Button_T == 1) {
            printf(roll_rad);
        }
        else if (Button_C == 1) {
            
        }
        // switch between roll and pitch(up vs. down button)

        // Scale your output value

        // Output your graph line

    }
    while (1); 
        
    
    
    
    return 0;
}
