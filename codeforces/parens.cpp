#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;

    int ans = 0;
    stack<char> st;
    for(auto c : s) {
        if(c == '(') st.push(c);
        else {
            if(st.size() && st.top() == '(') {
                ans += 2;
                st.pop();
            }
        }
    }

    cout << ans << '\n';




    return 0;
}