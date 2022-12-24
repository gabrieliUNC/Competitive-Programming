#include <bits/stdc++.h>
#define ll long long
using namespace std;

int factorial(int n){
    if(n==1 || n==0){
        return 1;
    }
    else{
        return n * factorial(n-1);
    }
}


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; int n = (3*t);
    ll comp = factorial(n);
    cout << comp << "\n";
    comp = ((n)*(factorial(n-1)-(factorial((n-1)-(n-t)))));
    cout << comp << "\n";
    return 0;
    }
