#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    char a[8][8]; int p[8];
    int ans = 1e9;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < k; ++j){
            cin >> a[i][j]; a[i][j] -= '0';
        }
    }

    for(int i = 0; i < k; ++i)p[i] = i;

    do{
        int Min = 1e9, Max = 0;
        for(int i = 0; i < n; ++i){
            int temp = 0;
            for(int j = 0; j < k; ++j){
                temp = temp*10 + a[i][p[j]];
            }
            Max = max(Max, temp);
            Min = min(Min, temp);
        }
        ans = min(ans, Max - Min);
    }while(next_permutation(p, p + k));


    cout << ans << '\n';

    return 0;
}