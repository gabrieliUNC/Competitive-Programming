#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int tt; cin >> tt;
    
    while(tt--){

    int len, k; cin >> len >> k;
 
    string s, t; cin >> s >> t;
 
    vector<int> a(len, 0);

    for (int i = 0; i < len; i++) if (i - k < 0 && i + k >= len) a[i] = 1;
 
    bool ok = 1;

    vector<int> check(26, 0);
    for (int i = 0; i < len; i++) {
      if (a[i]) ok = ok && (s[i] == t[i]);
      else {
        check[s[i] - 'a']++;
        check[t[i] - 'a']--;
      }
    }
 
    ok = ok && (check == vector<int>(26));
 
    cout << (ok ? "YES\n" : "NO\n");

    }
    return 0;
}