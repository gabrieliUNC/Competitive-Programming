#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int x = 1;

int main()
{
    
    if(fork() == 0){
        printf("child: %d\n", x++);
        exit(0);
    }
    else{
        printf("parent: %d\n", x--);
    }

    return 0;
}