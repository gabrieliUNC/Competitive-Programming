#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree< T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        ll ans = 0;
        Tree<ll> tree;
        for(int i = 0; i < n; ++i){
            ll tmp; cin >> tmp;
            ans += (i - tree.order_of_key(tmp));
            tree.insert(tmp);
        }
        cout << ans << '\n';
    }



    return 0;
}