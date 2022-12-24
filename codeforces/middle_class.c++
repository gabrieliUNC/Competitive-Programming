#include <bits/stdc++.h>
#define ll long long
using namespace std;


int solve(){
    ll n, x, count=-1; cin >> n >> x;
    long double total=0;
    long double v[n];
    for(int i=0; i<n; i++){
        int temp; cin >> temp;
        v[i] = temp;
        total+=temp;
    }
    
    int s = sizeof(v) / sizeof(v[0]);
    sort(v, v + n, greater <int>());

    if(v[0]>=x){
        while(count==-1){
            if((total/n)>=x){
                count=n;
            }
            else{
                total-=(v[n-1]);
                n--;
            }
        }
    }

    else{
        return 0;
    }
    return count;
}


main(){

    ll t; cin >> t;
    while(t--){
        cout << solve() << endl;
    }


    return 0;
}