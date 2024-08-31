#include <bits/stdc++.h>
#define ll long long
using namespace std;;

constexpr int mxN = 1e3 + 7;

ll A[mxN][mxN], pre[mxN][mxN];

void solve() {
    int n, q; cin >> n >> q;
    memset(A, 0, sizeof(A)); memset(pre, 0, sizeof(pre));

    for(int i = 0; i < n; ++i) {
        ll h, w; cin >> h >> w;
        A[h][w] += h * w;
    }

    for(int i = 1; i < mxN; ++i) {
        for(int j = 1; j < mxN; ++j) pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + A[i][j];
    }

    for(int i = 0; i < q; ++i) {
        int h_l, w_l, h_r, w_r; cin >> h_l >> w_l >> h_r >> w_r;

        cout << pre[h_r - 1][w_r - 1] - pre[h_l][w_r - 1] - pre[h_r - 1][w_l] + pre[h_l][w_l] << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();




    return 0;
}