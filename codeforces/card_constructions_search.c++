#include <bits/stdc++.h>
#define ll long long
using namespace std;


int solve(int n){
    if(n>=15){
        return 1 + solve(n-15);
    }
    else if(n>=7){
        return 1 + solve(n-7);
    }
    else if(n>=2){
        return 1 + solve(n-2);
    }
    else if(n<2){
        return 0;
    }
    return 0;
}


main(){
ll t; cin >> t;
while(t--){
    ll n; cin >> n;
    cout << solve(n) << endl;
}

    return 0;
}