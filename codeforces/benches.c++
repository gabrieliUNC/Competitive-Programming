#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, mint=INT_MAX, maxt=0; cin >> n >> m;
    int comp = m;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
        maxt = max(arr[i], maxt);
        mint = min(arr[i], mint);
    }
    if (maxt!=mint){
    for(int i=0; i<n; ++i){
        if(arr[i]<maxt){
            if(m>=(maxt-arr[i])){
                m-=(maxt-arr[i]);
                arr[i]+=(maxt-arr[i]);
            }
            else{
                arr[i]+=m;
                m=0;
            }
        }
        }
    }
    for(int e: arr){
        mint = max(mint, e);
    }
    mint += ceil((double) m / (double) n);

    maxt += comp;

    cout << mint << " " << maxt << endl;

        return 0;
}