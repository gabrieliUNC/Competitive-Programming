#include <bits/stdc++.h>
#define ll long long
#define TxtIO   freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

int main(){
    // TxtIO
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = 10e6 + 7;
    vector<int>a(n);
    for(int i = 0; i < n; ++i)cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i){
        int pos = 0;
        for(int j = i + 1, k = n - 1; j<=k;){
            int mid = (j+k)/2;
            if(a[mid] > a[i]*2) k = mid - 1;
            else if (a[mid]<=a[i]*2){
                j = mid + 1;
                pos = max(pos, mid);
            }
        }
        ans = min(ans, n-(pos-i+1));
    }
    
    cout << ans << '\n';




    return 0;
}