#include <bits/stdc++.h>
#define int long long
using namespace std;


unordered_map<int, int> mp;
int inf = 1e15;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);
    int n; cin >> n;
    int A[n];
    vector<int> prefix = {0};
    for(auto &e : A) {
        cin >> e;
        if(e > 0) prefix.push_back(e + prefix.back());
        else prefix.push_back(prefix.back());
    }

    

    array<int, 3> ans;
    ans[0] = -inf;

    mp.reserve(n);

    for(int i = 0; i < n; ++i) {
        if(mp.count(A[i])) {
            int j = mp[A[i]];

            int tmp = A[i] + A[j] + prefix[i] - prefix[j + 1];

            if(tmp > ans[0]) {
                ans[0] = tmp;
                ans[1] = j;
                ans[2] = i;
            }
            
        
        } else{
            mp[A[i]] = i;
        }

        
    }

    vector<int> rem;
    rem.reserve(n);

    for(int i = 0; i < ans[1]; ++i) rem.push_back(i + 1);
    for(int i = ans[1] + 1; i < ans[2]; ++i) {
        if(A[i] < 0) rem.push_back(i + 1);
    }
    for(int i = ans[2] + 1; i < n; ++i) rem.push_back(i + 1);

    // std::cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << '\n';

    std::cout << ans[0] << ' ' << rem.size() << '\n';

   for(auto e : rem) std::cout << e << ' ';
   std::cout <<'\n';




    return 0;
}