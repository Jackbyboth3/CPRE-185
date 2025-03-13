#include <stdio.h>
#include <math.h>
#include <time.h>

// Global variables to store acceleration data
double a, b, c;
int t;
// Function prototypes
double mag(double x, double y, double z);
int closeTo(double tolerance, double point, double value);
double startTime, endTime;
int counter = 0;

int main() {
    printf("%s", "Jack Byboth\n");
    printf("%s", "Jackbyb\n");

    printf("%s", "Ok, I'm now receiving data\n");

    // Waiting phase
    printf("Waiting");
    startTime = 0;
    while (1) {
        scanf(" %d,%lf,%lf,%lf", &t, &a, &b, &c);

        fflush(stdout);

        if (closeTo(25, 0, t % 100)) { // not moving
            printf(".");
        }
        if (closeTo(0.15, 0, mag(a, b, c))) {
            printf("\nHelp me! I'm falling");

            break;
        }
    }

    // Falling phase
    double velocity = 0;  // Init velocity
    startTime = t;
    while (closeTo(0.15, 0, mag(a, b, c))) {
        scanf(" %d,%lf,%lf,%lf", &t, &a, &b, &c);

        double accelerationMag = mag(a, b, c);
        velocity += 9.8 * (1 - accelerationMag) * ((t - startTime) / 1000.0);
        
        if (closeTo(25, 0, t % 10)) {
            printf("!");
        }
        fflush(stdout);
        endTime = t;
    }
    //new functions for air speed calculation
    double fallTime = (endTime - startTime) / 1000.0;
    double distanceWithAirResistance =  velocity * fallTime;
    double distance = (0.5 * 9.8) * (fallTime * fallTime);
    double percentageDifference = ((distance - distanceWithAirResistance) / distance);

    printf("\nCompensating for air resistance, the fall was %.3lf meters\n", distanceWithAirResistance);
    printf("This is %.2lf%% less than the distance computed in the last lab\n", percentageDifference);

    return 0;
}

// Magnitude function
double mag(double x, double y, double z) {
    return sqrt((x * x) + (y * y) + (z * z));
}

// Close to function
int closeTo(double tolerance, double point, double value) {
    if (value >= (point - tolerance) && value <= (point + tolerance)) {
        return 1;
    } else {
        return 0;
    }
}
