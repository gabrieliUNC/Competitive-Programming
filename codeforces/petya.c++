#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;


string solve(){
ll n, m, cnt=1; cin >> n >> m;
    int arr[m];
    for(ll i=0; i<m; i++){
        cin >> arr[i];
    }
    int n1 = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n1);
    if((arr[0]==1)||(arr[m-1])==n){
        return "NO";
    }
    else{
        ll prev=arr[0]+1;
        for(ll j=1; j<m; j++){
            if(arr[j]==prev){
                cnt++;
                if(cnt>2){
                    return "NO";
                }
            }
            else{
                cnt=1;
            }
            prev = arr[j]+1;
        }
    }
    return "YES";
}

main(){
    
    cout << solve() << endl;

    return 0;
}