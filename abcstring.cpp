#include <bits/stdc++.h>
#define pb push_back
using namespace std;


int solve() {
    string s; cin >> s;
    int n = size(s);

    unordered_map<char, set<int>> mp;
    for(int i = 0; i < n; ++i) {
        mp[s[i]].insert(i);
    }

    int ans = 1, idx = 0;
    string curr = "";
    while(n) {
        cout << idx << ' ';

        int next_a = INT_MAX, next_b = INT_MAX, next_c = INT_MAX;
        if(curr.find('A') == string::npos) next_a = *mp['A'].lower_bound(idx);
        if(curr.find('B') == string::npos) next_b = *mp['B'].lower_bound(idx);
        if(curr.find('C') == string::npos) next_c = *mp['C'].lower_bound(idx);

        int minn = min({next_a, next_b, next_c});
        if(minn == INT_MAX) {
            ans++;
            idx = 0;
        }

        if(minn == next_a) {
            curr += 'A';
            idx = next_a;
            mp['A'].erase(mp['A'].begin());
        }
        if(minn == next_b) {
            curr += 'B';
            idx = next_a;
            mp['B'].erase(mp['B'].begin());
        }
        if(minn == next_c) {
            curr += 'C';
            idx = next_a;
            mp['C'].erase(mp['C'].begin());
        }
        
        sort(begin(curr), end(curr));
        if(curr == "ABC") curr = "";
        n--;
    }

    return ans;

}

int main() {

    cout << solve() << '\n';    

    return 0;
}