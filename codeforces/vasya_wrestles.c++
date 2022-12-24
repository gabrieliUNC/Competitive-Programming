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
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;

int main(){
    START

    int n; cin >> n;
    vector <ll> a(n);
    vector <ll> b(n);
    vector <ll> in(n);
    ll sum = 0;

    loop(i, n){
        ll temp; cin >> temp;
        in[i] = temp;
        if(temp>0) a.push_back(temp);
        else b.push_back(-1*temp);
    }
    a.erase(remove(a.begin(), a.end(), 0), a.end());
    b.erase(remove(b.begin(), b.end(), 0), b.end());
    string greater = "";
    if(a[0]!=b[0]){
        greater = (a[0]>b[0] ? "first": "second");
    }    else{
        int i = 1;
        while(i<a.size() && i<b.size()){
            if(a[i]>b[i]){greater = "first"; break;}
            if(b[i]>a[i]){greater = "second"; break;}
            ++i;
        }
    }
    string last = in[in.size()-1]>0 ? "first" : "second";
    sort(all(a));
    sort(all(b));
    int size = (a.size() > b.size() ? a.size()-1 : b.size()-1);
    int i = 0;
    while(i<=size){
        if(i<a.size())sum+=a[i];
        if(i<b.size())sum-=b[i];
        i++;
    }
    if(sum==0){
        if(greater!="")cout << greater;
        else cout << last;
    }
    else if(sum>0) cout << "first";
    else cout << "second";


    return 0;
}

                                 
