#include <bits/stdc++.h>
using namespace std;

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    int a[n*2];
    for(int i=0; i<n*2; ++i)
        cin >> a[i];
    int ans = 1;
    int i = 1;
    while(i<a[n*2]){
        if(i+x < a[i]){
            i+=x;
        }
    }


    return 0;
}