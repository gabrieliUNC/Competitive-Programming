#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;

    vector<int> ans(2 * n + 1);

    for(int i = 1; i <= 2 * n; ++i) ans[i] = i;

    for(int i = 2; i <= 2 * n; i += 2) {
        if(k-- == 0) break;
        swap(ans[i], ans[i - 1]);
    }

    for(int i = 1; i <= 2 * n; ++i) cout << ans[i] << ' ';
    cout << '\n';



    return 0;
}