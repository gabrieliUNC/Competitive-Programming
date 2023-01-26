// PID: 730478505
// I pledge the COMP 211 honor code.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    const int MAGIC = 50;
    bool lines[100];
    int lines_over = 0;
    int j = 0;
    
    while(1){
        int i = 0, cnt = i + 1;

        char string[10000];
        
        fgets(string, 10000, stdin);
        if(string[0] == '\n') break;

        while(string[i] != '\0'){
            printf("%c", string[i]);
            if(cnt != 0 && cnt % MAGIC == 0){
                printf("\n");
                }
            if(i==51 && string[i]=='\n'){}
            ++i; ++cnt;
            }
        if(i > MAGIC){
            lines_over++;
            lines[j] = 1;
        }
        j++;
    }


    printf("\n");

    printf("Total lines over 50 chars: %d", lines_over);
    printf("\n");
    printf("Offending lines: ");

    for(int i = 0; i < j; ++i){
        if(lines[i]==1)printf("%d, ", i);
    }
    printf("\n");

    return 0;
}