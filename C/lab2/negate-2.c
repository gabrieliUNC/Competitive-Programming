// PID: 730478505
// I pledge the COMP 211 honor code.

#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv){
    char signed_integer[1000];
    strcpy(signed_integer, argv[argc - 1]);
    //Takes input from argv into signed_integer string

    int result[32];
    for(int i = 0; i < 32; ++i)result[i] = signed_integer[i] - '0';
    //changes string representation to int array

    for(int i = 0; i < 32; ++i)result[i] ^= 1;
    //takes complement of all bits

            for(int i = 31; i >= 0; --i){
                //adds one to binary representation
                result[i] ^= 1;
                if(result[i] == 1) break;
            }
    
    printf("The negation of the 32-bit two's complement integer %s is: ", signed_integer);
    for(int i = 0; i < 32; ++i)printf("%d", result[i]);
    printf(".\n");
}