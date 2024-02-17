#include <bits/stdc++.h>
#define inf 1e9
#define ld long double
using namespace std;

ld getWindow(vector<pair<int, int>>& v, ld time) {
    ld lo = inf;
    ld hi = -inf;
    for(auto& i : v) {
        ld val = i.first + i.second * time;
        lo = min(lo, val);
        hi = max(hi, val);
    }

    return hi - lo;
}

int main(){
    int n; cin >> n;
    vector<pair<int, int>> tanks(n);
    for(auto &p : tanks) cin >> p.first >> p.second;
    

    ld lo = 0, hi = 2e5;
    int ans = 1e5 + 7;

    while (hi - lo > 1e-7){
        ld r = (lo+hi*2)/3;
        ld l = (lo*2+hi)/3;

        ld r1 = getWindow(tanks, l);
        ld r2 = getWindow(tanks, r);

        
        if(r1 < r2){
            hi = r; 
        } else{
            lo = l;
        }
        
    }

    cout << fixed;
    cout.precision(5);
    cout << getWindow(tanks, lo) << '\n';

    return 0;
}