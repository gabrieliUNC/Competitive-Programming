#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();

    int cnt = 0, ans = 0;
    bool ok = 1;
 
    for(char c : s) {
        if(c == '(' || c == '<' || c == '{' || c == '[') ++cnt;
        else --cnt;
        if(cnt < 0) {
            ok = 0;
            break;
        }
    }

    if(cnt || !ok) { cout << "Impossible\n"; return 0; }

    stack<char> st;

    for(char c : s) {
        if(c == '(' || c == '<' || c == '{' || c == '[') st.push(c);
        else {
            if(c == ')') {
                if(st.top() != '(') ++ans;
                st.pop();
            }

            if(c == '}') {
                if(st.top() != '{') ++ans;
                st.pop();
            }

            if(c == ']') {
                if(st.top() != '[') ++ans;
                st.pop();
            }

            if(c == '>') {
                if(st.top() != '<') ++ans;
                st.pop();
            }

        }
    }

    cout << ans << '\n';

    
    

    return 0;
}