#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, k, ans = 0;
    cin >> n >> k;
    k *= 5;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());

    for(int i = 0; i < n; ++i){
        if (k >= a[i]) ++ans;
        k -= a[i];
    }
    cout << ans << '\n';

    return 0;
}