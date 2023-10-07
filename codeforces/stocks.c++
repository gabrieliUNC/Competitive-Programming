#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> prices(n);
    const int N = 3 * 1e4;
    int dp[N];
    
    
    for(int i = 0; i < n; ++i){
        int sum = 0;
        for(int j = i, k = j + 1; k < n; j += 2){
            if(prices[j] - prices[k] <= 0) continue;
            sum += prices[j] - prices[k];
        }
        
    }


    

    return 0;
}