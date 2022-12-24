#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; ll h, k, sum=0, ans=0; cin >> h >> k;
    ll arr[n];
    for(int i=0; i<n; ++i){cin >> arr[i]; sum+=arr[i];}
    int i=0;
    while(sum>0){
        if(i+1<n){
            if((arr[i]+arr[i+1])<=h){
                    arr[i+1] = arr[i] + arr[i+1];
                    i++;
                }
            else if(arr[i]<=k){
                sum-=arr[i];
                ans++;
                i++;
            }
            else{
                ans+=((arr[i]/k) >=1 ? (arr[i]/k) : 1);
                sum-=((arr[i])-(arr[i]%k));
                arr[i]%=k;
            }
        }
        
        else{
            if(arr[i]<=k){
                ans++;
                sum-=arr[i];
                i++;
            }
            else{
                ans+=((arr[i]/k)>=1 ? (arr[i]/k) : 1);
                sum-=((arr[i])-(arr[i]%k));
                arr[i]%=k;
                }
        }
    }
    cout << ans << "\n";


    return 0;
}