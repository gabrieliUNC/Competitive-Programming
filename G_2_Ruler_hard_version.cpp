#include <bits/stdc++.h>
using namespace std;

// int secret{0};

// int query(int a, int b) {
//     if(a >= secret)
//         a++;
//     if(b >= secret)
//         b++;

//     return a * b;
// }

void solve() {
    int l = 2, r = 999;

    for(int i = 0; i < 7; ++i) {
        
        int m1 = l + (r - l) / 3;
        int m2 = min(r - (r - l) / 3, r);

        // cout << m1 << ' ' << m2 << '\n';

        cout << "? " << m1 << ' ' << m2 << endl;
        fflush(stdout);

        int res; cin >> res;
        // int res = query(m1, m2);

        // both correct
        if(res == m1 * m2) {
            l = m2 + 1;
        }
        // one incorrect
        else if(res == m1 * (m2 + 1)) {
            l = m1 + 1;
            r = m2;
        } 
        // both incorrect
        else r = m1;
    }

    cout << "! " << r << endl;
    fflush(stdout);
}

int main() {
    int tt; cin >> tt;
    while(tt--) {
        solve();
    }
}