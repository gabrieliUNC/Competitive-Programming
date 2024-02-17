#include <bits/stdc++.h>
#define int long long
using namespace std;

int n = 0;

bool check(vector<int> people, vector<int> strengths, vector<int> speeds, int target){
    for(int boat = 0; boat < n; ++boat){
        bool ok = 0;
        for(int person1 = 0; person1 < 3; ++person1){
            if(ok) break;
            if(!people[person1]) continue;
            for(int person2 = 0; person2 < 3; ++person2){
                if(!people[person2] || (person1 == person2 && people[person1] < 2)) continue;
                
                if(speeds[boat] * (strengths[person1] + strengths[person2]) >= target){
                    people[person1]--;
                    people[person2]--;
                    ok = 1;
                    break;
                }
            }
        }
        if(!ok) return 0;
    }
    return 1;
    
}


signed main(){
    vector<int> people(3), strengths(3);
    for(int i = 0; i < 3; ++i) {
        cin >> people[i];
        n += people[i];
    }
    n /= 2;

    for(int i = 0; i < 3; ++i) cin >> strengths[i];

    vector<int> speeds(n);
    for(auto &e : speeds) cin >> e;
    sort(speeds.begin(), speeds.end());

    int l = 0, r = 1e18;

    
    while(r - l > 1){
        int mid = l + (r - l) / 2;
        
        if(check(people, strengths, speeds, mid)) {
            l = mid;
        } else{
            r = mid;
        }
    }

    cout << l << '\n';


    return 0;
}