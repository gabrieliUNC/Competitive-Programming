#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


int solve(){
int n; cin >> n;
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int x=n-1;
        while(a[x-1]>=a[x] && x>0) --x;
        while(a[x-1]<=a[x] && x>0) --x;
        return x;


}

main(){
    int tt; cin >> tt;
    while(tt--){
        cout << solve() << endl;
    }
}