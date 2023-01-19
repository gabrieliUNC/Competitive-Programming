#include <bits/stdc++.h>
using namespace std;

const int mxN = 1007;

int arr[mxN], a[mxN], b[mxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(arr, 0, mxN);
    int n; cin >> n;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i!=j && b[i]==a[j])arr[j] = 1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(arr[i]==0)ans++;;
    }
    cout << ans << '\n';


    return 0;
}