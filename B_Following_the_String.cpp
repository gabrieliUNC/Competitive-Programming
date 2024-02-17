#include <bits/stdc++.h>
using namespace std;

int alphabet[26];

void solve() {
    memset(alphabet, 0, sizeof(alphabet));
    int n; cin >> n;
    int A[n];
    for(auto &e : A) cin >> e;

    string ans = "";

    for(int i = 0; i < n; ++i) {
        int num = A[i];

        for(int j = 0; j < 26; ++j) {
            if(alphabet[j] == num) {
                ans += (char)(j + 97);
                alphabet[j]++;
                break;
            }
        }
    }

    cout << ans << '\n';


}

int main() {

    int tt; cin >> tt;

    while(tt--) solve();


    return 0;
}