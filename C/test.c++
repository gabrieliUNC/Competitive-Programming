#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int x = 1;

int main(){

    fork();
    
    if(pid == 0){
        printf("child: %d\n", x++);
        exit(0);
    }
    else{
        printf("parent: %d\n", x--);
    }

    return 0;



    return 0;
}