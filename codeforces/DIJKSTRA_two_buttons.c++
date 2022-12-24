#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k, ans=0; cin >> n >> k;
    ll dist[50001];
    for (int i = 0; i < 50001; ++i) {
        dist[i] = 1e8;
    }
    dist[n] = 0;
    if(n>k){
        cout << (n-k) << "\n";
        return 0;
    } else {
        //min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, n});
        while (pq.size()) {
            auto [weight, num] = pq.top(); pq.pop();
            if (num > 2LL * k) continue;
            if (num <= 0) continue;
            
            if (weight > dist[num]) continue;
            if (num == k) {
                cout << weight << '\n';
                return 0;
            }
            if (dist[num - 1] == 1e8)
                pq.push({weight + 1, num - 1});
            if (!(num * 2 > 2LL * k) && dist[num * 2] == 1e8)
                pq.push({weight + 1, num * 2});
            dist[num - 1] = weight + 1;
            dist[num * 2] = weight + 1;
            
        }
    }

    return 0;
}