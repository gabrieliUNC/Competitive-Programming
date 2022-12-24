#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 3;
set<int> people[mxN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int x, k; cin >> x >> k;
        if (people[k].find(x) != end(people[k])) continue;

        if (people[k].size() == 0) {
            if (x == 0) {
                people[k].insert(0);
            } else {
                ok = false;
            }
        } else {
            if (people[k].find(x - 1) != end(people[k])) {
                people[k].insert(x);
            } else {
                ok = false;
            }
        }
    }
    cout << (ok ? "YES" : "NO") << '\n';
    return 0;
}