#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    vector<vector<int>> ans;
    while (s.size()) {
        auto i = s.find('(');
        if (i == string::npos) {
            break;
        }
        auto j = s.rfind(')');
        if (j == string::npos) {
            break;
        }
        if (i > j) break;
        vector<int> current;
        vector<bool> skip(s.size(), false);
        while (i != string::npos && j != string::npos && i < j) {
            skip[i] = true;
            skip[j] = true;
            current.push_back(i + 1);
            current.push_back(j + 1);

            i = s.find('(', i + 1);
            j = s.rfind(')', j - 1);
        }
        sort(begin(current), end(current));
        if (current.size()) {
            string nxt = "";
            for (int i = 0; i < s.size(); ++i) {
                if (skip[i]) continue;
                nxt += s[i];
            }
            ans.push_back(current);
            s = nxt;
        }
    }

    cout << ans.size() << '\n';
    for (auto & c : ans) {
        cout << c.size() << '\n';
        for (auto& j : c) {
            cout << j << ' ';
        }
        cout << '\n';
    }



    return 0;
}