#include <bits/stdc++.h>
using namespace std;

static const int mxN = 2e5 + 8;
std::pair<int, int> cache[mxN];

void move(int num, int x, int y, int n, int m, vector<vector<int>>& A, vector<vector<int>>& B) {
    // Binary search for target
    auto [i, j] = cache[num];
    
    // swap rows
    if(i != x) {
        swap(B[i], B[x]);
        for(int k = 0; k < m; ++k) {
            cache[B[i][k]] = {i, k};
        }
        for(int k = 0; k < m; ++k) {
            cache[B[x][k]] = {x, k};
        }
    }
    // swap cols
    if(j != y) {
        for(int k = 0; k < n; ++k) {
            swap(B[k][j], B[k][y]);
            cache[B[k][j]] = {k, j};
            cache[B[k][y]] = {k, y};
        }
    }
}

bool solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m, 0)), B(n, vector<int>(m, 0));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> A[i][j];

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> B[i][j];
            cache[B[i][j]] = {i, j};
        }
    }
    
 
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            move(A[i][j], i, j, n, m, A, B);
        }
    }
    
    for(int i = 0; i < n; ++i)  
        for(int j = 0; j < m; ++j)
            if(A[i][j] != B[i][j]) return 0;
    return 1;
}


int main() {
    int tt; cin >> tt;

    while(tt--) {
        std::cout << (solve() ? "YES\n" : "NO\n");
    }


    return 0;
}