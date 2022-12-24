#include <iostream>
#include <array>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

main(){
    int t;
    cin >> t;
    int Sereja = 0;
    int Dima = 0;

    int array[t];
    int n = sizeof(array)/sizeof(array[0]);

    for(int i=0; i<t; i++){
        cin >> array[i];
    }
    sort(array, array+n, greater<int>());

    for (int j=0; j<t; j++){
        if(j%2==0){
            Sereja += array[j];
        }
        if(j%2==1){
            Dima += array[j];
        }
    }

    cout <<Sereja<<endl;
    cout <<Dima<<endl;
        return 0;
    }