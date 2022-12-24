#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, dif=0; cin >> n;
    vector <ll> in;
    vector <ll> ans;
    for(int i=0; i<n; ++i){
        ll temp; cin >> temp;
        in.push_back(temp);
    }
    sort(in.begin(), in.end());
    for(int i=1; i<n; ++i){
        dif = max(dif, in[i] - in[i-1]);
    }
    int i=0;
    int change = 0;
    while( i<n ){
        ll res = binary_search(in.begin(), in.end(), ans[i]+change);
        if(res!=-1){
            ans.push_back(res);
            i++;
        }
        else{
            change++;
        }
    }
    if(abs(ans.end()-ans.begin())>dif){
        res = binary_search(ans.begin(), ans.end(), )
    }

    return 0;
}