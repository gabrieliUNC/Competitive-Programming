#include <stdio.h>
#include <stdlib.h>


int main(){
    int a = 1, b = 1, c = 2, d = 5;

    int x = (1/(a + b)) * c + d;

    int ax = 1 / a + b * c + d;
    int bx = 1 / (a + b) * c + d;
    int cx = 1 / (a + b) * (c + d);
    int dx = c / (a + b) + d;
    int ex = (c + d) / (a + b);
    int fx = (1 / a + b * c + d);

    printf("%d\n %d\n %d\n %d\n %d\n %d\n %d\n", x , ax, bx, cx, dx, ex, fx);
    



}