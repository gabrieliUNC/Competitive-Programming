/*
** Date: !v strftime("%A, %d %B, %Y")`
** Time: !v strftime("%X")`
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define sz(x) (int)x.size()
template<typename FUNCTION>
#define loop(x,n) for(int x = 0; x < n; ++x)
#define loopd(x, n) for(int x = n; x>=0; --x)
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define START ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                                                            
#define CPU cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#define vi vector<int>;
#define vvi vector<vi>;
#define pii pair<int, int>;
#define vpii vector<pii>;

const int MOD = 1e9 + 7;
const ll inf = 1e18 + 5;
const ld pi = 3.1415292654589793;
const int maxn = 1e5 + 5;

int main(){
    START
    int n; cin >> n;
    map <int, int> in, out;
    vector<int> ans;
    int curr = 0;
    int count = 0;
    loop(i, n){
        int temp; cin >> temp;
        count++;
        if(temp>0){
            ++curr;
            in[temp]++;
            if(in[temp]>1){
                cout << -1;
                return 0;
            }
        }
        if(temp<0){
            --curr;
            out[temp]++;
            if(in.count(-1*temp)!=1 || out[temp]>1){
                cout << -1;
                return 0;
            }
        }
        if(curr==0){
            ans.push_back(count);
            in.clear();
            out.clear();
            count = 0;
            }

    }
    
    if(curr!=0)cout << -1;
        else{
        cout << ans.size() << '\n';
        for(int e: ans){
            cout << e << ' ';
        }
        }




    return 0;
}

                                 
