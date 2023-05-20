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
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;

int k = 1;

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    if((a.first)/k != (b.first)/k)
    {
        return a.first/k < b.first/k;
    }
    return a.second < b.second;
}

void add(map<ll, ll> &m, ll x, ll &res){
    if(m[x] == x) --res;
    m[x]++;
    if(m[x] == x) ++res;
}

void del(map<ll, ll> &m, ll x, ll &res){
    if(m[x] == x) --res;
    m[x]--;
    if(m[x] == x) ++res;
}


int main(){
    START
    
    int n, q; cin >> n >> q;
    k = sqrt(n) + 1;

    vector<ll> a(n);
    loop(i, n) cin >> a[i];

    vector<pair<ll, ll>> ask(q);

    map<ll, ll> m;

    loop(i, q){
        int a, b; cin >> a >> b;
        ask[i] = {a, b};
    }

    sort(ask.begin(), ask.end(), comp);

    vector<ll> ans(q);
    ans.clear();

    int cur_l = 0;
    int cur_r = 0;
    ll res = 0;
    int i = 0;

    for(pair<ll, ll> p: ask){
        int l = p.first;
        int r = p.second;
        l--;
        r--;

        while(cur_r < r){
            add(m, a[cur_r], res);
            cur_r++;
        }

        while(cur_l > l){
            del(m, a[cur_l], res);
            cur_l--;
        }

        while(cur_r > r){
            del(m, a[cur_r], res);
            cur_r--;
        }

        while(cur_l < l){
            add(m, a[cur_l], res);
            cur_l++;
        }
        ans[i++] = res;
    }

    loop(i, q) cout << ans[i] << '\n';

    return 0;
}

                                 
