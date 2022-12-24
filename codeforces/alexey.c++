#include <iostream>
#include <vector>
#include <array>
#include <bits/stdc++.h>

using namespace std;

main(){
int t;
cin >> t;
int array[t];

for(int j=0; j<t; j++){
    cin >> array[j];
}

long long int n = sizeof(array) / sizeof(array[0]);

sort(array, array + n);
long long int x=0; long long int y=0; int x_i=t-1; int y_i=0;

for (int i=0; i<t; i++){
    if(i%2==0){
        x+=array[x_i];
        x_i--;
    }
    else{
        y+=array[y_i];
        y_i++;
    }
}

cout << (x*x) + (y*y);
return 0;
}