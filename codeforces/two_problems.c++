#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, t, a, b, a_dec, b_dec; cin >> x >> t >> a >> b >> a_dec >> b_dec;

    bool solved = 0;

    if(x == 0) solved = 1;

    for(int i = 0; i < t; ++i){
        if(i) a -= a_dec;
        int temp = b;
        for(int j = 0; j < t; ++j){
            if(j) temp -= b_dec;
            if(a < 0) a = 0;
            if(temp < 0) temp = 0;
            if((a == x) || (temp == x) || (a + temp == x)){
                solved = 1;
                break;
            }
        }
        if(solved) break;
    }

    if(solved) cout << "YES" << '\n';
    else cout << "NO" << '\n';


    return 0;
}