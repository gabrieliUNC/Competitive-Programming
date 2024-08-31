#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 2e5 + 7;
int C[mxN], b[mxN];

double eval(int& n, double x_0) {
    double f = 0.0;
    for(int i = 0; i < n; ++i) {
        f = max(abs((double) C[i] - x_0) + (double) b[i], f);
    }
    return f;
}

void solve() {
    int n; cin >> n;
    for(int i = 0; i < n; ++i) cin >> C[i];
    for(int i = 0; i < n; ++i) cin >> b[i];


    int its = 128;

    double l = 0.0, r = 1e9, eps = 1e-9;

    for(int i = 0; i < its; ++i) {
        double mid1 = l + (r - l) / 3.0;
        double mid2 = r - (r - l) / 3.0;

        double f1 = eval(n, mid1);
        double f2 = eval(n, mid2);

        if(f1 - f2 < eps) {
            r = mid2;
        } else {
            l = mid1;
        }
    }

    cout << fixed;
    cout << setprecision(12);
    cout << r << '\n';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;

    while(tt--) solve();




    return 0;
}