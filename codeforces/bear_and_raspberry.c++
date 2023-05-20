#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k, dif = -1; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];


    for(int i = 0; i < n - 1; ++i) dif = max(dif, a[i] - a[i + 1]);

    if(dif - k >= 0) cout << dif - k << '\n';
    else cout << 0 << '\n';


    return 0;
}