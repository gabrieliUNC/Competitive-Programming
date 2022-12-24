#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        ll n; cin >> n; int s, k; cin >> s >> k;
        vector <int> comp;
        for(int i=0; i<k; ++i){
            int temp; cin >> temp;
            comp.push_back(temp);
        }
        sort(comp.begin(), comp.end());
        int ans = 0;
        int left = false;
        int right = false;
        for(int x=0; x<=k; x++){
            left = (s+x)<=n && find(comp.begin(), comp.end(), s+x)==comp.end();
            right = (s-x)>=1 && find(comp.begin(), comp.end(), s-x)==comp.end();
            if (left){
                ans = x;
                break;
            }
            else if(right){
                ans = x;
                break;
            }
        }
        cout << ans << "\n";
    }





    return 0;
}