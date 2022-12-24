#include <bits/stdc++.h>
#define ll long long
using namespace std;


main(){

    ll int n, result; cin >> n;
    if(n==1){
        cout << 1;
    }

    else if((n%(n-1))!=0&&((n-1)!=1)){
        cout << 1;
    }
    else{
        cout << n;
    }



    return 0;
}