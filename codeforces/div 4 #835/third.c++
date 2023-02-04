#include <bits/stdc++.h>
#define ll long
#define ld long double
#define pb push_back
#define all(x) begin(x), end(x)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<ll> arr(n);
        vector <pair<ll, ll>> check(n);
        vector<ll> ans;
        for(int i=0; i<n; ++i){
            cin >> arr[i];
        }
        for(int i=0; i<n; ++i){
            check[i] = {i, arr[i]};
        }
        sort(check.begin(), check.end(), [](auto &left, auto &right){
            return left.second > right.second;
        });
        
        for(int i=0; i<n; ++i){
            for(pair<ll, ll> e: check){
                if(e.first!=i){
                    ans.push_back(arr[i]-e.second);
                    break;
                }
            }
        }

        for(int e: ans){
            cout << e << " ";
        }
        cout << '\n';
    }


    return 0;
}