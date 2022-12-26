#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //each element of subarray must be at least 1/2 previous element
    //subarray is size k + 1
    int t; cin >> t;
    
    while(t--){

        int n, k; cin >> n >> k;

        ll a[n];

        for(int i = 0; i < n; ++i)
            cin >> a[i];


        int b[n];
        
        
        for(int i = 0; i + 1 < n; ++i){
            b[i] = (a[i] < a[i+1]*2);
        }


        int curr = 0;

        int ans = 0;

        for(int i=0; i<k; ++i)
            curr += b[i];

        if(curr==k)ans++;
        
        for(int i = k; i < n-1; ++i){
            curr += b[i];
            curr -= b[i-k];
            if(curr==k)ans++;
        }
        
        cout << ans << '\n';
    }




    return 0;
}