#include<bits/stdc++.h>
#define ld long double
using namespace std;

ld calc(ld pred, ld length){
    return pred * cosh(length / ((ld)2.0 * pred)) - pred;
}

ld ans(ld pred, ld length){
    return ((ld)2.0 * pred) * sinh(length / ((ld)2.0 * pred));
}

int main(){
    int length, sag; cin >> length >> sag;
    ld lo = 0, hi = 1e18, e = 0.0000000001;

    while(hi - lo > e) {
        ld mid = (lo + (hi - lo) / 2.0);

        ld sag_pred = calc(mid, length);

        if(sag_pred <= sag){
            hi = mid;
        } else{
            lo = mid;
        }
    }

    cout << fixed;
    cout << setprecision(9);
    cout << ans(lo, length) << '\n';


    return 0;
}