#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

main(){
int tt; cin >> tt;
while(tt--){
    ll n, count=0; cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=1;i<n;i++){
        count+=max(0, arr[i-1]-arr[i]);
    }

    cout << count << endl;
    
}
return 0;
}