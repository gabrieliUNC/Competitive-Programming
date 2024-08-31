#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l = 2, r = 999;

    while(l < r) {
        int mid = (l + r) / 2;
        cout << "? " << mid << ' ' << mid << endl;
        fflush(stdout);

        int area;
        cin >> area;

        if(area != mid * mid) {
            r = mid;
        } else l = mid + 1;
    }

    cout << "! " << r << endl;
    fflush(stdout);
}

int main() {
    int tt; cin >> tt;
    while(tt--)
        solve();
}