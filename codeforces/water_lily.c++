#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

main(){
    double height, length, divisor, quotient; cin >> height >> length;
    cout << fixed;
    setprecision(15);
    cout << ((pow(length, 2)-pow(height, 2))/(2*height));
    return 0;
    }
