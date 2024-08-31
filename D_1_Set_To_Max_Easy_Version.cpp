#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;

    vector<int> a(n), b(n);

    for(auto& e : a)
        cin >> e;
    for(auto& e : b)
        cin >> e;

    vector<pair<int, int>> sorted;
    for(int i = 0; i < n; ++i)
        sorted.push_back({b[i], i});
    
    sort(begin(sorted), end(sorted));

    for(int i = 0; i < n; ++i) {
        int idx = sorted[i].second, val = sorted[i].first;

        if(a[idx] >= val)
            continue;
        
        int l = idx - 1, r = idx + 1;
        while(l >= 0 && a[l] <= val && val <= b[l]) {
            if(a[l] == val)
                break;
            l--;
        }

        if(l >= 0 && a[l] == val) {
            for(int j = l; j <= idx; ++j)
                a[j] = val;
            continue;
        }

        while(r < n && a[r] <= val && val <= b[r]) {
            if(a[r] == val)
                break;
            r++;
        }

        if(r < n && a[r] == val) {
            for(int j = idx; j <= r; ++j)
                a[j] = val;
        }

    }

    // for(auto& e : a)
    //     cout << e << ' ';

    if(a == b)
        cout << "YES\n";
    else cout << "NO\n";
    
}

int main() {

    int tt; cin >> tt;

    while(tt--)
        solve();





    return 0;
}