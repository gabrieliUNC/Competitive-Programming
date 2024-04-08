#include <bits/stdc++.h>
#define ll long long
using namespace std;


int getDigits(ll num) {
    int ans = 0;
    while(num) {
        ans += (num % 10);
        num /= 10;
    }
    return ans;
}


void solve() {
    int n, q; cin >> n >> q;
    int A[n];
    for(int i = 0; i < n; ++i) cin >> A[i];

    set<int> pos;
    stack<int> rem;
    for(int i = 0; i < n; ++i) pos.insert(i);

    for(int i = 0; i < q; ++i) {
        int type; cin >> type; --type;

        if(type) {
            int idx; cin >> idx; idx--;
            cout << A[idx] << '\n';
        } else {
            int l, r; cin >> l >> r; l--; r--;
            if(!size(pos)) continue;

            auto it = pos.lower_bound(l);

            for(it; it != pos.end(); ++it) {
                int idx = *it;
                if(idx > r) break;
                A[idx] = getDigits(A[idx]);
                if(A[idx] < 10) rem.push(idx);
            }
            while(size(rem)) {
                pos.erase(rem.top());
                rem.pop();
            }
        }
    }


}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while(tt--) solve();




    return 0;
}