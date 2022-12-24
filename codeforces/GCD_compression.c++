#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
ll t; cin >> t;
while(t--){
    ll n, x=0, y=0; cin >> n;
    int ans_it = n-1;
    vector<int> e(0);
    vector <int> o(0);
    vector < pair <int, int> > ans;
    for(int i=1; i<n*2+1; i++){
    int temp;
        cin >> temp;
        if (temp%2==0){
            e.push_back(i);
        }
        else{
            o.push_back(i);
        }
    }
    for(int i = 0; i + 1 < o.size(); i += 2)
			ans.push_back({o[i], o[i + 1]});
		for(int i = 0; i + 1 < e.size(); i += 2)
			ans.push_back({e[i], e[i + 1]});
		for(int i = 0; i < n - 1; i++)
			cout << ans[i].first << " " << ans[i].second << endl;
}

}