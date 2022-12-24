#include <bits/stdc++.h>
using namespace std;


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    int ans = 1;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int i = 0;
    while(i<n){
        ans = ans == arr[i] ? ans+1 : ans;
        i++;
    }
    cout << ans << "\n";


    return 0;
}