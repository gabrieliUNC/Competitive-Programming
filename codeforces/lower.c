// PID: 730478505
// I pledge the COMP 211 honor code.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    
    char character; scanf("%c", &character);
    const int LOWER = 65; const int HIGHER = 90; const int DELTA = 32;

    while(character != '\0' && character != '\n'){
        int ascii = character;
        if(ascii <= HIGHER && ascii >= LOWER)ascii += DELTA;
        char out = ascii;
        printf("%c", out);
        scanf("%c", &character);
    }


    printf("\n");

    return 0;
}