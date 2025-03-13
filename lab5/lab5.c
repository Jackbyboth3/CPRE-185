#include <stdio.h>
#include <math.h>
#include <time.h>

// Global variables to store acceleration data
double  a, b, c;
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
        
        
        if (closeTo(25 , 0, t % 100)) { // not moving
            printf(".");
                
               
            }
            if(closeTo(0.15 , 0, mag(a, b, c))) {
                printf("\nHelp me! I'm falling");
                
                break;
            }
        }  
    
    
    // Falling phase
    startTime = t;
    while (closeTo(0.15, 0, mag(a, b, c))) {
        scanf(" %d,%lf, %lf, %lf", &t,&a, &b, &c);
        
        
            if (closeTo(25, 0 ,t % 10)) {
                printf("!");
               
            }
            fflush(stdout);
            endTime = t;
        
    }
    double fallTime = (endTime - startTime) / 1000.0;
    double distance = (0.5 * 9.8) * (fallTime * fallTime);
    printf("\nOuch! I fell %.3f meters in %.3f seconds.\n", distance, fallTime);
    return 0;
    
}
    
       
        
// magnitude function
double mag(double x, double y, double z) {
    return sqrt((x * x) + (y * y) + (z * z));
}

// Close to function
int closeTo(double tolerance, double point, double value) {
    if (value >= (point - tolerance) && value <= (point + tolerance)) {
        return 1;
    }
    else {
        return 0;
    }
}
