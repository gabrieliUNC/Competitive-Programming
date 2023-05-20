#include <bits/stdc++.h>
#define ll long long
using namespace std;


const double FRAC = 1e-9 - 8;
const int INF = 1e9 + 7;

int gauss (vector < vector<double> > a, vector<double> & ans) {
    int n = (int) a.size();
    int m = (int) a[0].size() - 1;

    vector<int> where (m, -1);
    for (int col=0, row=0; col<m && row<n; ++col) {
        int sel = row;
        for (int i=row; i<n; ++i)
            if (abs (a[i][col]) > abs (a[sel][col]))
                sel = i;
        if (abs (a[sel][col]) < FRAC)
            continue;
        for (int i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (int i=0; i<n; ++i)
            if (i != row) {
                double c = a[i][col] / a[row][col];
                for (int j=col; j<=m; ++j)
                    a[i][j] -= a[row][j] * c;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (int i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = a[where[i]][m] / a[where[i]][i];
    for (int i=0; i<n; ++i) {
        double sum = 0;
        for (int j=0; j<m; ++j)
            sum += ans[j] * a[i][j];
        if (abs (sum - a[i][m]) > FRAC)
            return 0;
    }

    for (int i=0; i<m; ++i)
        if (where[i] == -1)
            return INF;

    return 1;
}

int main(){
    int n; cin >> n;
    vector< vector<double> > a;
    vector<double> ans;
    a.clear();
    ans.clear();

    for(int i = 0; i < n; ++i){
        vector<double> temp;
        temp.clear();
        for(int i = 0; i < n + 1; ++i){
            double t; cin >> t;
            temp.push_back(t);
        }
        a.push_back(temp);
    }

    gauss(a, ans);

    cout << fixed;
    cout << setprecision(12);
    for(double e : ans) cout << e << '\n';

}