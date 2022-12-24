#include "bits/stdc++.h"
using namespace std;
#define ll long long

main(){
    ll buttons=0, bulbs=0, count=0; cin >> buttons >> bulbs;
    ll int arr1[bulbs+1] {};
    for(int j=1; j<=bulbs; j++){
        arr1[j]=0;
    }
    while (buttons--){
        int t; cin>>t;
        for(int i=1; i<=t; i++){
            ll a; cin >> a;
            if(arr1[a]==0){
                arr1[a]=1;
            }
        }

}
for(int x=1; x<=bulbs; x++){
    if (arr1[x]==1){
        count++;
    }
}
if(count==bulbs){
    cout << "YES";
}
else if (count!=bulbs){
    cout << "NO";
}
return 0;
}