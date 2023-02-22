#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll total = a + b + c + d;
        if(a == 0){ cout << 1 << '\n'; continue; }
        ll sum = 2 * min(b, c);
        sum += a;
        sum += min(a + 1, abs(b - c) + d);

        cout << sum << '\n';
    }


    return 0;
}