// PID: 730478505
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv){
    char signed_integer[1000];
    scanf("%s", signed_integer);
    bool pos = signed_integer[0] == '+' ? 1 : 0;
    int num = atoi(signed_integer);
    if(num > 32767 || num < -32768){ printf("The signed 16-bit representation of %d is: not possible.", num); return 0; }

    int result[16];
    for(int i = 0; i < 16; ++i)result[i] = 0;
    int i = 0;

    while(num != 0){
        if((num % 2 == 1) || (num % 2 == -1))result[i] = 1;
        else result[i] = 0;
        num /= 2;
        ++i;
    }

    int ans[16];
    for(int i = 0; i < 16; ++i)ans[i] = result[15 - i];

    if(pos){
        printf("The signed 16-bit of representation %s is: ", signed_integer);
            for(int i = 0; i < 16; ++i)printf("%d", ans[i]);
            printf(".\n");        
    }

    else{
        ans[0] = 1;
        printf("The signed 16-bit of representation %s is: ", signed_integer);
            for(int i = 0; i < 16; ++i)printf("%d", ans[i]);
            printf(".\n");        

    }





    return EXIT_SUCCESS;
}