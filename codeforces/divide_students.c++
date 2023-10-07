#include <bits/stdc++.h>
using namespace std;


void solve(){
    int a, b, c; cin >> a >> b >> c;
    int one = 0, two = 0, three = 0;
    int optimal = ceil(double(a + b + c) / 3.0);
    int worst;

    if((a + b) * 2 < c) { worst = ceil((double)c / 2.0); }
    if((b + c) * 2 < a) { worst = ceil((double)a / 2.0); }

    if(a > c){
        two = a - optimal;
        a -= two;
        one = c;
    } else{
        two = c - optimal;
        c -= two;
        one = a;
    }

    while(b){
            if(one <= two && one <= three) { one++; b--; continue; }
            if(two <= one && two <= three) { two++; b--; continue; }
            if(three <= one && three <= two) { three++; b--; continue; }
    }

    cout << max({a, b, c, worst}) << '\n';

    


}

int main(){
    int tt; cin >> tt;

    while(tt--) solve();




    return 0;
}