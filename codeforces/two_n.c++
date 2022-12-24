#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[n]; 
        ll twos = 0;
        ll sum = pow(2, n);
        for(int i=0; i<n; ++i){
            cin >> a[i];
            while(a[i]%2==0){
                a[i]/=2;
                ++twos;
            }
        }
        int i = n-1;
        int cnt = 0;
        while(sum%twos!=0 && i>=2){
            cout << "HERE";
            int temp = i;
            int pos = 0;
            while(temp%2==0){
                temp/=2;
                ++pos;
            }  
            if(twos*pos<sum){
                ++cnt;
                twos*=pos;
            }
            i-=2;
        }

        if(sum%twos==0) cout << cnt << "\n";
        else cout << -1 << "\n";


    }




    return 0;
}