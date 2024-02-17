#include <bits/stdc++.h>
using namespace std;

const int inf = 1e8;
vector<vector<int>> rooms;
enum room_closed {
    NONE = 0, R = 1, L = 2
};

int dp[201][201][3];

int f(int k, int i, room_closed status) {
    if(k == 0) return 0;
    if(i < 0) return inf;
    int res = (f(k, i - 1, NONE));
    if(dp[k][i][status] != -1) return dp[k][i][status];

    switch (status) {
        case R:
            res = min(res, f(k - 1, i - 1, R) + rooms[i][1]);
            break;
        case L:
            res = min(res, f(k - 1, i - 1, L) + rooms[i][0]);
            break;
        case NONE:
            int right = min(res, f(k - 1, i - 1, R) + rooms[i][1]), left = min(res, f(k - 1, i - 1, L) + rooms[i][0]);
            res = min({res, left, right});
            break;
    }
    return dp[k][i][status] = res;
}

int main() {
    int n, k, total = 0; cin >> n >> k;
    rooms.resize(n, vector<int>(2));
    for(int i = 0; i < n; ++i) {
        cin >> rooms[i][0] >> rooms[i][1];
        total += rooms[i][0] + rooms[i][1];
    }

    for(int i = 0; i <= k; ++i)
        for(int j = 0; j <= n; ++j)
            for(int x = 0; x < 3; ++x)
                dp[i][j][x] = -1;


    cout << total - f(k, n - 1, NONE) << '\n';
    



    return 0;
}