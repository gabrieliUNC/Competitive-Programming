#include <bits/stdc++.h>
#define ll long long
#define d 31
ll prime = 1e9 + 9;
using namespace std;

unordered_map<string, int> precomp() {
    unordered_map<string, int> strs;
    for(int day = 1; day <= 31; ++day) {
        for(int month = 1; month <= 12; ++month) {
            if(month == 2 && day > 28) continue;
            if(month == 4 && day > 30) continue;
            if(month == 6 && day > 30) continue;
            if(month == 9 && day > 30) continue;
            if(month == 11 && day > 30) continue;

            for(int year = 2013; year <= 2015; ++year) {
                string da, m, y;
                if(day < 10) da = "0" + to_string(day);
                else da = to_string(day);
                if(month < 10) m = "0" + to_string(month);
                else m = to_string(month);
                y = to_string(year);
                strs[(da + "-" + m + "-" + y)] = 0;
            }
        }
    }
    return strs;
}

int main() {
    string s; cin >> s;
    int n = size(s);

    auto strs = precomp();

    vector<ll> power(10, 0);
    for(int i = 0; i < 10; i++) power[i] = (i == 0)? 1 : ((power[i - 1] * d) % prime);

    unordered_map<ll, int> hash;
    ll cur = 0;

    for(int i = 0; i < 10; ++i) {
        cur *= d;
        cur %= prime;
        cur += (s[i] == '-' ? 11 : (s[i] - '0' + 1));
        cur %= prime;
        if(cur < 0) cur += prime;
    }
    hash[cur] = 0;
    if(strs.count(s.substr(0, 10)))
        strs[s.substr(0, 10)]++;

    for(int i = 10; i < n; ++i) {
        cur -= (power[9] * (s[i - 10] == '-' ? 11 : (s[i-10] - '0' + 1))) % prime;
        if(cur < 0) cur += prime;
        cur = (cur * d + (s[i] == '-' ? 11 : (s[i] - '0' + 1))) % prime;
        // if(hash.count(cur)) cout << i << '\n';

        // if(s.substr(i-9, 10) == "12-12-2013") cout << cur << '\n';
        if(!hash.count(cur)) {
            hash[cur] = i - 10 + 1;
            if(strs.count(s.substr(i - 10 + 1, 10))) strs[s.substr(i - 10 + 1, 10)]++;
        }
        else {
            string t = s.substr(hash[cur], 10);
            if(strs.count(t) && t == s.substr(i - 10 + 1, 10)) strs[t]++;
        }
    }

    string ans = ""; int o = 0;

    for(auto& [str, cnt] : strs) {
        if(cnt > o) {
            ans = str;
            o = cnt;
        }
    }   

    cout << ans << '\n';

    return 0;
}