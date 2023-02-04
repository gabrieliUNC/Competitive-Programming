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

void dfs(vector<vector<char>> &a, int i, int j, int &dots, vector<vector<int>> &v, int &x, int &y){
    if(v[i][j] == 1) return;
    if(a[i][j] == '.') dots--;
    v[i][j] = 1;
    if(i + 1 < y && ((a[i + 1][j] == ' ') || (a[i + 1][j] == '.'))){dfs(a, i + 1, j, dots, v, x, y);}
    if(i - 1 >= 0 && ((a[i - 1][j] == ' ') || (a[i - 1][j] == '.'))){dfs(a, i - 1, j, dots, v, x, y);}
    if(j + 1 < x && ((a[i][j + 1] == ' ') || (a[i][j + 1] == '.'))){dfs(a, i, j + 1, dots, v, x, y);}
    if(j - 1 >= 0 && ((a[i][j - 1] == ' ') || (a[i][j - 1] == '.'))){dfs(a, i, j - 1, dots, v, x, y);}
    return;
}

int main(){
    START

    vector<pair<int, int>> entrances;
    int dots = 0;

    int x, y; cin >> x >> y;
    vector<vector<char>> a(x, vector<char>(y));
    string s; 
    for(int i = 0; i < x; ++i){
        s = "";
        getline(cin, s);
        if(!i)getline(cin, s);
        int j = 0;
        for(char c: s){
            a[i][j] = c;
            if(a[i][j] == '.')dots++;
            else if((c != 'X') && (c != ' ')){entrances.push_back({i, j});}
            j++;
        }
    }

    vector<vector<int>> v(x, vector<int>(y, 0));

    

    int first = 0;

    for(pair<int, int> e: entrances){
        int temp = dots;
        if(dots > 0)dfs(a, e.first, e.second, dots, v, x, y);
        else break;
        if(temp != dots)first++;
    }

    cout << first << ' ' << dots << '\n';



    return 0;
}

                                 
