#include <stdio.h>
#include <math.h>
# define M_PI           3.14159265358979323846

int main() {

    int a = 6427 + 1725;
    int b = (6971 * 3925) - 95;
    double c = 79 + 12 / 5;  // use lf for double
    double d = 3640.0 / 107.9;
    int e = (22 / 3) * 3;
    int f = 22 / (3 * 3);
    double g = 22 / (3 * 3);
    double h = 22 / 3* 3;
    double i = (22.0 / 3) * 3.0;
    int j = 22.0 / (3 * 3.0);
    double k = 22.0 / 3.0 * 3.0;

    printf(" 6427 + 1725 = %d\n", a); 
    printf(" (6427 * 3925) -95 = %d\n", b);
    printf("79 + 12 / 5 = %lf\n", c);
    printf("3640.0 / 107.9 = %lf\n", d);
    printf("(22 / 3) * 3 = %d\n", e);
    printf("22 / (3 * 3) = %d\n", f);
    printf("22 / (3 * 3) = %lf\n", g);
    printf("(22.0 / 3) * 3.0 = %lf\n", h);
    printf("(22.0 / 3) * 3.0 = %lf\n", i);
    printf("22.0 / (3 * 3.0) = %d\n", j);
    printf("22.0 / 3.0 * 3.0 = %lf\n", k);

    double l = M_PI * pow(3.751,2);
    int m = 14/3.28084;
    int n = (76 - 32) / 1.8;

    printf("pi * 3.751^2 = %f\n", l);
    printf("14ft/3.28084m = %d\n", m);
    printf("(76 - 32) / 1.8 = %d\n", n);

    return 0;
}