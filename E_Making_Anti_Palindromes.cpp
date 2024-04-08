#include <bits/stdc++.h>
using namespace std;


int solve() {
    int n; cin >> n;
    string s; cin >> s;
    if(n % 2) return -1;
    vector<int> matches(26, 0);

    for(int i = 0; i < n; ++i) {
        ++matches[s[i] - 'a'];
    }

    for(auto& match : matches) if(match > n / 2) return -1;

    
    int pairs = 0;
    vector<int> cnt(26, 0);

    for(int i = 0; i < n / 2; ++i) {
        if(s[i] == s[n - i - 1]) {
            ++pairs;
            ++cnt[s[i] - 'a'];
        }
    }
    for(auto& match : cnt) if(match > pairs / 2) return match;


    return (pairs + 1) / 2;


}

int main() {

    int tt; cin >> tt;

    while(tt--) {
        cout << solve() << '\n';
    }



    return 0;
}