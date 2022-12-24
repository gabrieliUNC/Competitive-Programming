#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<long long, long double>& a, pair<long long, long double>& b){
    if(a.second==b.second){
        return a.first<b.first;
    }
        return a.second>b.second;

}

void sort_now(map<long long, long double>& ans)
{
  
    vector<pair<long long, long double>> v;
    for(auto &it: ans){
        v.push_back(it);
    }

    sort(v.begin(), v.end(), cmp);

    for(auto& it: v){
        cout << it.first << ' ' << fixed << setprecision(2) << it.second << "\n";
    }
}


main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n; cin >> n;
    long double t1, t2; cin >> t1 >> t2;
    long double k; cin >> k;
    k = (1-(.01*k));
    bool greater = (t1*k) > t2 ? true : false;
    map <long long, long double> ans;
    long double curr=0, next = 0, pause = 0;
    for(long long i=0; i<n; ++i){
        cin >> curr >> next;
        if(curr>=next){
            pause = greater==true ? (curr*t1*k) + (next*t2) : (curr*t2) + (next*t1*k);
            ans.insert({i+1, pause});
        }
        else{
            pause = greater==true ? (next*t1*k) + (curr*t2) : (next*t2) + (curr*t1*k);
            ans.insert({i+1, pause});
        }
    }

    sort_now(ans);



    return 0;
}