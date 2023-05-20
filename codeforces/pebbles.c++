#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;

    vector<int> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int low = *min_element(a.begin(), a.end());
    int high = *max_element(a.begin(), a.end());

    if(abs(high - low) > k){ cout << "NO" << '\n'; return 0; }

    cout << "YES" << '\n';

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < a[i]; ++j){
            if(j % k) cout << j % k + 1 << ' ';
            else cout << 1 << ' ';
        }
        cout << '\n';
    }



    return 0;
}