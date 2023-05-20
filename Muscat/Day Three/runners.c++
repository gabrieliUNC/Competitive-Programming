#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double

#define sz(x) (int)x.size()
template<typename FUNCTION>
#define loop(x,n) for(int x = 0; x < n; ++x)
#define loopd(x, n) for(int x = n; x>=0; --x)
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

vector<pair<ll, ll>> lines;

ld intersection(pair<ll, ll> line1, pair<ll, ll> line2){
    return ((ld)(line1.second - line2.second) / (line2.first - line1.first));
}

bool can_delete(pair<ll, ll> line1, pair<ll, ll> line2, pair<ll, ll> line3){
    return intersection(line1, line2) < intersection(line2, line3);
}

void add_line(ll k, ll b){
    pair<ll, ll> new_line = make_pair(k, b);
    while(lines.size() >= 2 && can_delete(lines[lines.size() - 2], lines.back(), new_line)){
        lines.pop_back();
    }
    lines.push_back(new_line);
}

ll val_line(int pos, ll x){
    return lines[pos].first * x + lines[pos].second;
}

ll compute_min(ll x){
    int l = -1;
    int r = lines.size() - 1;

    while(r - 1 > l){
        int mid = (l + r) / 2;
        if (val_line(mid, x) > val_line(mid + 1, x)){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return val_line(r, x);
}

int n;

int main(){
    START
    
    cin >> n;

    vector<ll> x(n + 1), a(n + 1), b(n + 1);

    for(int i = 1; i < n + 1; ++i) cin >> x[i] >> a[i] >> b[i];
    add_line(0, 0);
    vector<ll> dp(n + 1);

    for(int i = 1; i < n + 1; ++i){
        ll F = compute_min(-b[i]);
        F += (x[i] * b[i] + a[i]);
        dp[i] = F;
        cout << F << '\n';
        add_line(x[i], dp[i]);
    }
    


    return 0;
}

                                 
