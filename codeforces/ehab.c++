#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        vector <int> in;
        int sum = 0;
        for(int i=0; i<n; ++i){
            int temp; cin >> temp;
            sum += temp;
            in.push_back(temp);
        }
        if((sum%x)!=0){
            cout << n << "\n";
            continue;
        }
        else{
            int i = 0;
            int j = n-1;
            for(i; i<n; ++i){
                if(((sum-in[i])%x)!=0){
                    break;
                }
            }
            for(j; j>=0; --j){
                if(((sum-in[j])%x)!=0){
                    break;
                }
            }
            if(i!=n){
                cout << ((i+1) < (n-j+1) ? (n-i-1) : (j)) << "\n";
            }
            else{
                cout << -1 << "\n";
            }
        }
        
    }



    return 0;
}