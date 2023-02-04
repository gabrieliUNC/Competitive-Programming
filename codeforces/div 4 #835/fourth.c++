#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, cnt=0; cin >> n;
        ll arr[n];
        for(int i=0; i<n; ++i) cin >> arr[i];
        if(n==1)cout<< "YES" << '\n';
        else{
        ll prev = arr[0];
        vector <ll> a;
        a.push_back(arr[0]);
        for(int i=1; i<n; ++i){
            while(arr[i]==prev)++i;
            if (i < n) {
                a.push_back(arr[i]);
                prev = arr[i];
            }
        }
        if (a.size() >= 2) {
            if(a[0]<a[1])cnt++;
            if(a[a.size()-1]<a[a.size()-2])cnt++;
        } else {
            cnt++;
        }
        for(int i=1; i<a.size()-1; ++i){
            if(a[i]<a[i-1] && a[i]<a[i+1])cnt++;
        }


        if(cnt==1){
            cout << "YES" << '\n';
        }
        else{
            cout << "NO" << '\n';
        }
    }
    }
    



    return 0;
}