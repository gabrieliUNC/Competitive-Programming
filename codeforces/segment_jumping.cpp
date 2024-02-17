#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--){
        int n; cin >> n;

        vector<pair<int, int>> a(n);
        for(auto &e : a) cin >> e.first >> e.second;
        int ans = INT_MAX;

        int l = -1, r = 1e9 + 8;

        while(r - l > 1){
            int mid = (l + r) / 2;
            pair<int, int> pos = {0, 0};

            bool ok = 1;

            for(int i = 0; i < n; ++i){
                int left = a[i].first, right = a[i].second;

                pos.first = max(pos.first - mid, left);
                pos.second = min(pos.second + mid, right);
                if(pos.first > pos.second) {ok = 0; break; }
            }
            if(ok) r = mid;
            else l = mid;
        }

        cout << r << '\n';
    }

    return 0;
}