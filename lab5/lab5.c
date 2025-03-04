#include <stdio.h>
#include <math.h>

double a,b,c;
double mag(double x, double y, double z);
int close_to (double tolerance, double point, double value);

int main () {
    printf(" %s", "Jack Byboth\n");
    printf(" %s", "Jackbyb\n");

    scanf("%lf, %lf, %lf", a , b, c);
    print(" %s","Ok, im now receiving data");
    
    // waiting 
    //while(closeTo(mag())) {
        //printf(" %s ""im Waiting");
        // timer printf(" %s" ".");
    //}

    // falling 
    //while (closeTo(mag())) {
        //print("")
    //}
    
    // Ouch 
    // printf(" %s, metersVar, secondsVar ","Ouch! I fell {meters} in {seconds}")
    return 0;
}

double mag(double x, double y, double z) {
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}
//need closeTo function
int closeTo(double tolerance, double point, double value){

}





