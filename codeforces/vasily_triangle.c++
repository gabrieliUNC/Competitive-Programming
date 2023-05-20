#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll x, y, a, b, c, d; cin >> x >> y;
    ll sum = abs(x) + abs(y);

    if(x < 0){
        a = sum * -1LL; b = 0;

        if(y < 0){
            c = 0; d = sum * -1LL;
        } else{
            c = 0; d = sum;
        }

    } else{
        a = 0; b = sum;

        if(y < 0){
            c = sum * -1LL; d= 0;
        } else{
            c = sum; d = 0;
        }
    }



    cout << a << ' ' << c << ' ' << b << ' ' << d << ' ' << '\n';



    return 0;
}