#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, result, limit; cin >> n >> result >> limit;
    vector<ll> suffix(n + 1);
    vector<int> b(n);
    for(int i = 0; i < n; ++i) b[i] = i % 2 ? 1 : limit;

    if(n % 2) suffix[n] = 1;   
    else suffix[n] = limit;

    
    for(int i = n; i > 1; --i) suffix[i - 1] = b[i - 1] - suffix[i];
    for(int e : suffix) cout << e << ' ';



    return 0;
}