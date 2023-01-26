#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k;
        vector<ll> a(n + 1);
        for(int i = 1; i <= n; ++i)cin >> a[i];

        priority_queue<ll> pq;
        ll ans = 0, sum = 0;

        for(int i = k; i > 1; --i){
            sum -= a[i]; pq.push(a[i]);
            if(sum < 0){
                sum += 2 * pq.top();
                pq.pop();
                ++ans;
            }
        }

        while(!pq.empty())pq.pop();
        sum = 0;
        for(int i = k + 1; i <= n; ++i){
            sum += a[i]; pq.push(-a[i]);
            if(sum < 0){
                sum += 2 * pq.top();
                pq.pop();
                ++ans;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}