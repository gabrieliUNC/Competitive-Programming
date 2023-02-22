// PID: 730478505
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv){
    const int UPPER = 32767;
    const int LOWER = -32768;
    char signed_integer[1000];

    strcpy(signed_integer, argv[argc - 1]);
    //Takes input from argv into signed_integer string

    bool is_positive = signed_integer[0] == '+' ? 1 : 0;
    int num = atoi(signed_integer);

    if(num > UPPER || num < LOWER){ printf("The signed 16-bit representation of %s is: not possible.", signed_integer); return 0; }

    int result[16];
    for(int i = 0; i < 16; ++i)result[i] = 0;
    int i = 0;

    while(num != 0){
        //formats integer into binary representation
        if((num % 2 == 1) || (num % 2 == -1))result[i] = 1;
        else result[i] = 0;
        num /= 2;
        ++i;
    }

    int ans[16];
    for(int i = 0; i < 16; ++i)ans[i] = result[15 - i];
    //reverses binary representation to match true form

    if(is_positive){
        printf("The signed 16-bit representation of %s is: ", signed_integer);
            for(int i = 0; i < 16; ++i)printf("%d", ans[i]);
            printf(".\n");        
    }

    else{
        ans[0] = 1;
        printf("The signed 16-bit representation of %s is: ", signed_integer);
            for(int i = 0; i < 16; ++i)printf("%d", ans[i]);
            printf(".\n");        

    }





    return EXIT_SUCCESS;
}
