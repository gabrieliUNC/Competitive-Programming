#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 2;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    int siz = 0;
    map<int, pair<int, int>> pos;
    vector<int> leftQueries;
    int time = 0;
    while(q--){
    char c; cin >> c;
    int k; cin >> k;
    
    if(c=='L'){
        siz++;
        pos[k] = {0, time};
        leftQueries.push_back(time);
    }
    if(c=='R'){
        siz++;
        pos[k] = {siz, time};
    }
    
    if(c=='?'){
        auto it = lower_bound(begin(leftQueries), end(leftQueries), pos[k].second);
        int dff = (end(leftQueries) - it);
        int idx = pos[k].first + dff;
        cout << min(idx - 1, siz - idx) << '\n';
    }

    ++time;
}


    return 0;
}