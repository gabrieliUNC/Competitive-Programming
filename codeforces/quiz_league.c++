#include <bits/stdc++.h>
#define ll long long
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
using namespace std;

main(){
TxtIO;
ll n, k, ans {0}; cin >> n >> k;
vector<int> a(n+1, 0);
    for(int i=1; i<(n+1); i++){
        cin >> a[i];
    }
    while(ans==0){
        if(a[k%(n+1)]==1){
            ans = (k%(n+1));
            break;
        }
        k++;
    }

    cout << ans << endl;
    return 0;
}
