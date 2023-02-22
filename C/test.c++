#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w+",stdout);
using namespace std;


int mystery(char *s){
    char *t;
    for(t = s; *t != '\0'; t++);
    return t - s;
}

int main(){
    char string0[] = "COMP Joke:";
    printf("%d", mystery(string0));



    return 0;
}