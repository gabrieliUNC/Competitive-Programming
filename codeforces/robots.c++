#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)cin >> a[i];
    int k = 0;
    int ans = 0;
    while(k<n){
        if(ans%2==0){
            for(int i = 0; i < n; ++i){
                if(a[i]<=k){k++; a[i]=INT_MAX;}
                if(k==n)break;
            }
            ans++;
        }
        else{
            for(int i = n-1; i>=0; --i){
                if(a[i]<=k){k++; a[i]=INT_MAX;}
                if(k==n)break;
            }
            ans++;
        }
    }
    ans--;
    cout << ans << '\n';


    return 0;
}