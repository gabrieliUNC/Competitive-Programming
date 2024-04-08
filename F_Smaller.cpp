#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<vector<long long>> B(2, vector<long long>(26,0));
    B[0][0] = B[1][0] = 1;

    int q; cin >> q;
    for(int i = 0; i < q; ++i) {
        int d, k; cin >> d >> k;
        d--;
        string cur; cin >> cur;
        for(auto& c : cur) B[d][c - 'a'] += k;
        auto A = B;
        int l = 0, r = 25;

        // while(A[0][l] == 0) l++;
        // while(A[1][r] == 0) r--;
        bool ok = 0;

        while(l <= r) {
            if(A[0][l] == 0) { l++; continue; }
            if(A[1][r] == 0) { r--; continue; }
            if(l < r) {
                ok = 1;
                break;
            }
            if (A[0][l] < A[1][r]) {
                ok = 1;
                for (int j = l + 1; j <= 25; j++) if (A[0][j]) {ok = 0; break;}
                break;
            } else if (A[0][l] > A[1][r]) {
                break;
            }
            l++;
            r--;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}

int main() {
    int tt; cin >> tt;
    while(tt--) solve();

}