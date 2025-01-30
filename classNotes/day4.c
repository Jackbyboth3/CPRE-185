#include <stdio.h>

int main(void) {
    int anInt = 0;
    double f,g,earthToSun;

    anInt = 77;
    f = 3.1415926;
    char yn;
    yn = 'Y'; // cant use double "" because literal string/char
    printf("%d.25, %lf/n", anInt, f);

    return 0;
}