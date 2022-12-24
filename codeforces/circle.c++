#include <bits/stdc++.h>
#define ll long long
using namespace std;

void swap(int x, int y, int arr[]){
    int temp = arr[y];
    arr[y] = arr[x];
    arr[x] = temp;
}

main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector <int> arr;
    int arr[n];
    for(int i=0; i<n; ++i){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    
    cout << ans[ans.size()-1];
    for(auto e: ans){
        cout << e << " ";
    }

    return 0;
}