#include <bits/stdc++.h>
using namespace std;
#define ul long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ul n, s; cin >> n >> s;
    ul k = 10;
    ul ans = n;
    if(!(k<=n)){
        cout << n; return 0;
    }

    while(k<=n){
        ul sub = n%k+1;
        if(n%k==(k-1)) sub = 0;
        if(sub<=s) ans = n - sub;
        if(n==k) break;
        k*=10;
    }
    cout << ans;
    

    return 0;
}