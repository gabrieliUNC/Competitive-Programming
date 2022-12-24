#include <iostream>
#include <bits/stdc++.h>
using namespace std;

main(){
    int t;
    cin >> t;
    t-=1;
    int comp;
    cin >> comp;
    int min = comp;
    int max = comp;
    int count=0;
    while (t--){
        int a;
        cin >> a;
        if(a>max){
            count+=1;
            max = a;
        }
        if(a<min){
            count +=1;
            min=a;
        }
    }
    cout << count;

    return 0;
}