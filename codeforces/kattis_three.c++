#include<bits/stdc++.h>
using namespace std;




int main(){
    int n, k, c; cin >> n >> k >> c;
    map<int, int> cap;
    vector<pair<int, int>> teams, ans;

    for(int i = 0; i < n; ++i){
        int team, school; cin >> team >> school;
        if(!cap.count(school)) cap[school] = 0;

        if(cap[school] < c && k > 0){
            cap[school]++;
            ans.push_back({i, team});
            --k;
        } else{
            teams.push_back({i, team});
        }
    }

    sort(teams.begin(), teams.end());
    auto curr = teams.begin();

    while(k > 0){
        ans.push_back({curr->first, curr->second});
        ++curr;
        --k;
    }

    sort(ans.begin(), ans.end());

    for(auto i = ans.begin(); i != ans.end(); ++i){
        cout << i->second << '\n';
    }




    return 0;
}