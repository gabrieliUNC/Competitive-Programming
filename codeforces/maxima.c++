#include <bits/stdc++.h>
using namespace std;


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t-->0){
        int n, k; cin >> n >> k;
        vector <bool> a(n); 
        bool one = false;
        bool zero = false;
        for(int i=0; i<n; ++i){
            int temp; cin >> temp;
            a.push_back(temp);
            if (temp==1) { one = true; }
            if (temp==0) { zero = true; }
        }

        if(!one) { cout << "NO" << "\n"; }
        else if (!zero) { cout << "YES" << "\n"; }
        else if (k<2) { cout << "NO" << "\n"; }
        else { cout << "YES" << "\n"; }
    }



    return 0;
}