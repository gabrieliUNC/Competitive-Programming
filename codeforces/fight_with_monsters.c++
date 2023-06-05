#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);

    int AP, BP, skips; cin >> AP >> BP >> skips;
    for(int i = 0; i < n; ++i) cin >> a[i];

    vector<int> track(n);

    int hp;
    int skip;

    for(int i = 0; i < n; ++i){
        skip = 0;

        if(a[i] - (AP + BP) <= 0){
            hp = a[i] - AP;
            if(hp - BP <= 0){
                if(hp > 0){
                    skip = hp / AP;
                    if(hp % AP) ++skip;
                    track[i] = skip;
                } else{
                    track[i] = 0;
                }
                continue;
            }
            
            hp = a[i];
            int turn = 0;
            while(hp > 0){
                if(skip > skips) break;
                if(!turn){
                    hp -= AP;
                } else if(hp - BP <= 0){
                    ++skip;
                } else{
                    hp -= BP;
                }
                turn ^= 1;
            }

            track[i] = skip;
            continue;
        }

        hp = a[i] % (AP + BP);

        if(hp == 0){
            hp += BP;
            skip = hp / AP;
            if(hp % AP) ++skip;
            track[i] = skip;
            continue;
        } else{
            int turn = 0;
            while(hp > 0){
                if(skip > skips) break;
                if(!turn){
                    hp -= AP;
                } else if(hp - BP <= 0){
                    ++skip;
                } else{
                    hp -= BP;
                }
                turn ^= 1;
            }

            track[i] = skip;
            continue;
        }
        
        track[i] = 0;
    }

    sort(track.begin(), track.end());

    int ans = 0;

    for(int i = 0; i < n; ++i){
        // cout << track[i] << ' ';
        if(skips - track[i] >= 0) skips -= track[i];
        else break;
        ++ans;
    }
    // cout << '\n';

    cout << ans << '\n';

    return 0;
}