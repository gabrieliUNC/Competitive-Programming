#include <bits/stdc++.h>
#define ll long
#define ld long double
#define pb push_back
#define all(x) begin(x), end(x)
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while(t--){
        int arr[3];
        for(int i=0; i<3; ++i){
            cin >> arr[i];
    }
    sort(arr, arr+3);
    cout << arr[1] << "\n";

    }
    return 0;

}