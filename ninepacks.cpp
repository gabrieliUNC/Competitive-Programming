#include <bits/stdc++.h>
using namespace std;


const int mxN = 1e5 + 8;
vector<int> hotdogs(mxN, mxN);
vector<int> buns(mxN, mxN);


int main() {
    hotdogs[0] = 0;
    buns[0] = 0;
    int n; cin >> n;
    for(int i = 0; i < n; ++i) {
        int num; cin >> num;
        for (int j = mxN - num - 1; j >= 0; --j) {
            if(hotdogs[j] < hotdogs[j + num]) {
                hotdogs[j + num] = hotdogs[j] + 1;
            }
        }
    }
    
    

    int m; cin >> m;
    for(int i = 0; i < m; ++i) {
        int num; cin >> num;
        for (int j = mxN - num - 1; j >= 0; --j) {
            if(buns[j] < buns[j + num]) {
                buns[j + num] = buns[j] + 1;
            }
        }
    }

    

    int ans = INT_MAX;
    for(int i = 1; i < mxN; ++i) {
        if(hotdogs[i] && buns[i]) ans = min(ans, hotdogs[i] + buns[i]);
    }
    
    if(ans >= mxN / 2) cout << "impossible\n";
    else cout << ans << '\n';


    return 0;
}