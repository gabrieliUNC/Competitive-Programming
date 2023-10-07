#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> musicians;
vector<int> ans;

bool f(int idx, int time, int m1, int m2, vector<int> v, int sz){
    //Base Cases
    if(time == t){
        if(!m1 && !m2 && sz == n - 1) {ans = v; return 1; }
        else return 0;
    }
    if(idx == n){
        return f(0, time + 1, m1 - 1, m2 - 1, v, sz);
    }

    //Take or Dont Take
    int take1 = 0, take2 = 0, dontTake = f(idx + 1, time, m1, m2, v, sz);

    //Select 1st Musician
    if(!m1){
        v[idx] = time;
        take1 = f(idx + 1, time, musicians[idx], m2, v, sz + 1);
    }

    //Select 2nd Musician
    else if(!m2){
        v[idx] = time;
        take2 = f(idx + 1, time, m1, musicians[idx], v, sz + 1);
    }

    if(take1 || take2 || dontTake) return 1;
    return 0;
}


int main(){
    cin >> t >> n;
    musicians.resize(n);
    ans.resize(n);
    for(int i = 0; i < n; ++i) cin >> musicians[i];
    vector<int> v(n, 0);

    cout << boolalpha;
    cout << f(0,0,0,0,v,0) << '\n';
    for(auto e : ans) cout << e << ' ';
    cout << '\n';


    return 0;
}