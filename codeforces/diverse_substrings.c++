#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans = n;
        vector <vector<int>> prefix(n, vector<int>(10, 0));
        int arr[n];
        string s; cin >> s;
        for(int i=0; i<n; ++i){
            arr[i] = s[i] - '0';
            if (i > 0 ) {
                prefix[i] = prefix[i - 1];
            }
            prefix[i][arr[i]]++;
        }
        
        for(int i=0; i<n; ++i){
            for (int len = 2; i + len - 1 < n && len <= 100; ++len) {
                bool ok = true;
                auto copy = prefix[i + len - 1];
                auto before = i > 0 ? prefix[i - 1] : vector<int>(10, 0);
                for (int j = 0; j < 10; ++j) {
                    copy[j] -= before[j];
                }

                //copy has the frequency of characters in the substring [i, i + len - 1]

                int distinct = 0;
                for (int j = 0; j < 10; ++j) {
                    if (copy[j] > 0) distinct++;
                }
                for(int j=0; j<10; j++){
                    if(copy[j] > distinct){
                        ok = false;
                    }
                }

                if (ok) ans++;
            }
        }
        cout << ans << endl;



    }


    return 0;
}