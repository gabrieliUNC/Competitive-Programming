#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, target, ans = 1; cin >> n >> target;

    int A[n], suffix[n], prefix[n];
    for(auto &e : A) cin >> e;

    int mode = 0;
    for(int i = n - 1; i >= 0; --i) {
        if(A[i] == target) ++mode;
        suffix[i] = mode;
    }

    mode = 0;
    for(int i = 0; i < n; ++i) {
        if(A[i] == target) ++ mode;
        prefix[i] = mode;
    }

    ans = max(ans, min(mode + 1, n));

    
    unordered_map<int, int> mp;
    mp[A[0]]++;
    int freq = 1, start = 0;

    for(int i = 1; i < n; ++i) {
        mp[A[i]]++;
        freq = max(freq, mp[A[i]]);

        if(i + 1 < n && start - 1 >= 0) ans = max(ans, freq - (prefix[i] - prefix[start]) + prefix[start - 1]  + suffix[i + 1]);
        if(start - 1 >= 0) ans = max(ans, freq - (prefix[i] - prefix[start]) + prefix[start - 1]);
        if(i + 1 < n) ans = max(ans, freq - (prefix[i] - prefix[start]) + suffix[i + 1]);

        ans = max(ans, freq);

        if(freq == prefix[i] - prefix[start]) {
            start = i + 1;
            freq = 0;
            mp.clear();
        }
    }


    cout << ans << '\n';


    return 0;
}