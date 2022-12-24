#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll sum = 0;
        vector <int> pos(n);
        for(int i=0; i<n; ++i){
            cin >> pos[i];
            sum += pos[i];
        }   
        for(int i=n; i>=1; --i){
            if(sum%i==0){
                ll check = sum/i;
                ll curr = 0; 
                bool ok = true;
                for(int j=0; j<n; ++j){
                    curr+=pos[j];
                    if(curr > check){
                        ok = false;
                        break;
                    }
                    else if(curr==check){
                        curr=0;
                    }
                }
                if(ok){
                    cout << n-i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}