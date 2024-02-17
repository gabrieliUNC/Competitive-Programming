#include <bits/stdc++.h>
using namespace std;


int solve(){
    int n; cin >> n;
    vector<int> a(n);
    for(auto &e : a) cin >> e;
    int pos = distance(a.begin(), min_element(a.begin(), a.end())), dif = -1;
    for(int i = pos + 1; i < n; ++i){
        if(a[i] < a[i - 1]) return -1;
    }
    return pos;
    
}

int main(){
    int tt; cin >> tt;

    while(tt--) cout << solve() << '\n';



    return 0;
}