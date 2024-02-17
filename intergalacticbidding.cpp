#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n, t; cin >> n >> t;
    vector<pair<int, string>> bids;

    for(int i = 0; i < n; ++i) {
        string name; cin >> name;
        int bid; cin >> bid;
        bids.push_back({bid, name});
    }

    sort(bids.begin(), bids.end(), greater<pair<int, string>>());

    vector<string> ans;

    for(auto& [bid, name] : bids) {
        if(t >= bid) {
            t -= bid;
            ans.push_back(name);
        }
    }
    

    
    if(t == 0) {
        cout << ans.size() << '\n';
        if(ans.size()) {
            for(auto name : ans) cout << name << '\n';
        }
    } else {
        cout << 0 << '\n';
    }

    return 0;
}