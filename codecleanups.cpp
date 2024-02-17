#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, ans = 0; cin >> n;
    vector<int> days(366, 0);
    for(int i = 0; i < n; ++i) {
        int tmp; cin >> tmp;
        days[tmp] = 1;
    }
    vector<int> c;

    for(int i = 1; i <= 365; ++i) {
        int num = 0;
        for(auto commit : c) {
            num += (i - commit);
        }
        if(num >= 20) {
            ++ans;
            c.clear();
        }
        if(days[i]) c.push_back(i);
    }

    if(c.size()) ++ans;

    cout << ans << '\n';


    return 0;
}