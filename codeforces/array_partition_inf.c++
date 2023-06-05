#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m, k; cin >> n >> m >> k;
    multiset<int> s;
    vector<int> a(n); for(int i = 0; i < n; ++i){ cin >> a[i]; s.insert(a[i]); }

    for(int i = 0; i < n - (m * k); ++i){
        auto itr = s.begin();
        s.erase(itr);
    }

    int sum = 0;
    for(int elt : s) sum += elt;


    vector<int> p; p.clear();
    int curr = m;
    for(int i = 0; i < n; ++i){
        auto itr = s.find(a[i]);
        if(curr == 0 && itr != s.end()){
            s.erase(itr);
            if((int) p.size() != k - 1) p.push_back(i);
            curr = m - 1;
        }
        else if(curr != 0 && s.find(a[i]) != s.end()){
            s.erase(itr);
            --curr;
        }
    }

    cout << sum << '\n';
    for(int elt : p) cout << elt << ' ';
    cout << '\n';

    return 0;
}