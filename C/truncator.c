// PID: 730478505
// I pledge the COMP 211 honor code.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    const int MAGIC = 50;
    bool lines[300];
    for (int i = 0; i < 300; ++i) lines[i] = 0;
    int lines_over = 0;
    int j = 0;
    char c;
    int cnt = 0;
    int line_num = 0;

    while((c=getchar())!=EOF){
        if(cnt == MAGIC + 1 && c == '\n')continue;
        bool has_newline = false;
        if(cnt%MAGIC==0 && cnt != 0){putchar('\n'), has_newline = true; cnt = 0;}

        cnt++;
        if (c == '\n' && has_newline) {

        } else {
            putchar(c);
        }
        if(c=='\n'){
            cnt = 0;
            j = 0;
            line_num++;
        } else {
            j++;
        }


        if (j >= MAGIC) {
            //line has over 50
            lines[line_num] = 1;
        }
    }


    if(cnt!=MAGIC)printf("\n");
    lines_over = 0;
    for (int i = 0; i <= line_num; ++i) if (lines[i]==1) lines_over++;
    if(cnt==MAGIC){
        lines_over = 0;
        line_num = -1;
    }
    printf("Total lines over 50 chars: %d", lines_over);
    printf("\n");
    printf("Offending lines: ");


    for(int i = 0; i <= line_num; ++i){
        if(lines[i]==1)printf("%d, ", i);
    }

    return 0;
}
