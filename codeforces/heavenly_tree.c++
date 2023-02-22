#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        set<int> s;
        for(int i = 1; i <= n; ++i) s.insert(i);
        for(int i = 0; i < m; ++i){
            int a, b, c; cin >> a >> b >> c;
            s.erase(b);
        }

        int root = *s.begin();

        for(int i = 1; i <= n; ++i){
            if(i != root){
                cout << root << ' ' << i << '\n';
            }
        }
        

    }



    return 0;
}