#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n);
        ll ans = 1; bool zero = 0;
        for(int i = 0; i < n; ++i){cin >> a[i]; if(a[i]==0)zero = 1;}
        if(!zero)ans++;
        sort(a.begin(), a.end());
        for(int i = 0; i < n - 1; ++i){
            if(a[i] <= i && a[i+1] > i + 1)ans++;
        }
        

        cout << ans << '\n';
    }






    return 0;
}