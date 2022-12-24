#include <bits/stdc++.h>
#define ll long long 
using namespace std;


main(){
ll E = (pow(10, 5));
long double dp[E];
for(ll i=1; i<E; i++){
    long double j = i;
    dp[i] = ((3*(pow(j, 2)))/2) + (j/2);
}
ll t; cin >> t;

while (t--){
ll n, count=0; cin >> n;

while(n>=2){  
for(ll x=1; x<E; x++){
    if(n<dp[x]){
        if(n>=dp[x-1]){
            n-=dp[x-1];
            count++;
            break;
        }
    }
    if(n==dp[x]){
        n-=dp[x];
        count++;
        break;
    }
}
    }
    cout << count << endl;
}
return 0;
}

