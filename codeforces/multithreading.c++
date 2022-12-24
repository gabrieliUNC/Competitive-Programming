#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    int i = n - 1;
    for(i; i>0; --i){
        if(a[i-1]>a[i]) break;
    }
    cout << i << '\n';




    return 0;
}