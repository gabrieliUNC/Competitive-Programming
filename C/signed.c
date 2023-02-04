// PID: 730478505
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv){
    char signed_integer[1000];
    strcpy(signed_integer, argv[argc - 1]);
    bool pos = signed_integer[0] == '+' ? 1 : 0;
    int num = atoi(signed_integer);
    int result[16];
    for(int i = 0; i < 16; ++i)result[i] = 0;
    int i = 0;
    while(num > 0){
        if(num % 2 == 1)result[i] = 1;
        else result[i] = 0;
        num /= 2;
        ++i;
    }
    if(pos){
        printf("The signed bit representation of +%d is: ", signed_integer);
        for(int i = 15; i >= 0; --i)printf("%d", result[i]);
        printf("\n");        
    }
    else{
        printf("The signed bit representation of -%d is: ", signed_integer);
        for(int i = 15; i >= 0; --i)printf("%d", result[i]);
        printf("\n");        
    }




    return EXIT_SUCCESS;
}