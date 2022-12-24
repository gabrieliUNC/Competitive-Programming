#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long double solve(){
    long double t;
    cin >> t;
    double count;
    for(int i=0; i<t; i++){
        double a; cin >> a;
        count +=a;
    }
    return count / t;
}

main(){
    cout << solve();

    return 0;
}