#include <stdio.h>
#include <math.h>

// Global variables to store acceleration data
double a, b, c;

// Function prototypes
double mag(double x, double y, double z);
int closeTo(double tolerance, double point, double value);

int main() {
    printf("%s", "Jack Byboth\n");
    printf("%s", "Jackbyb\n");

    printf("%s", "Ok, I'm now receiving data\n");
    
    // Waiting phase
    int waitCounter = 0;
    while (1) {
        scanf("%lf, %lf, %lf", &a, &b, &c);
        double acceleration = mag(a, b, c);
        
        if (closeTo(0.5, 9.8, acceleration)) { // Assuming 9.8 m/s^2 as normal gravity
            waitCounter++;
            if (waitCounter % 10 == 0) {
                printf(".");
                fflush(stdout);
            }
        } else {
            printf("\nHelp me! I'm falling!!!!!!!!!!!!!\n");
            break;
        }
    }
    
    // Falling phase
    double startTime = 0, endTime = 0;
    int fallCounter = 0;
    while (1) {
        scanf("%lf, %lf, %lf", &a, &b, &c);
        double acceleration = mag(a, b, c);
        
        if (fallCounter == 0) {
            startTime = clock(); // Start timing the fall
        }
        
        fallCounter++;
        if (fallCounter % 5 == 0) {
            printf("!");
            fflush(stdout);
        }
        
        if (closeTo(2.0, 9.8, acceleration)) { // Detect landing
            endTime = clock();
            break;
        }
    }
    
    // Compute time and fall distance
    double fallTime = (endTime - startTime) / CLOCKS_PER_SEC;
    double distance = 0.5 * 9.8 * fallTime * fallTime;
    
    // Print final output
    printf("\nOuch! I fell %.3f meters in %.3f seconds.\n", distance, fallTime);
    
    return 0;
}

// Function to compute the magnitude of acceleration
double mag(double x, double y, double z) {
    return sqrt(x * x + y * y + z * z);
}

// Function to check if a value is close to a reference point within a given tolerance
int closeTo(double tolerance, double point, double value) {
    return fabs(value - point) < tolerance;
}
