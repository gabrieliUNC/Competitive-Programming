#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t-->0){
        int n; cin >> n;
        int arr[n+1];
        if(n==1){
            cout << 1 << "\n";
        }
        else{
        for(int i=1; i<=n; ++i)
            cin >> arr[i];
        int prev = arr[n-1];
        int i = n;
        int j = 1;
        while(j<=n){
            while(prev>=arr[i]){
                arr[i] += j;
                cout << i << "\n";
                j++;
            }
            i--;
            prev = arr[i-1];
        }

    cout << "==============================" << "\n";
    }
}
return 0;
}