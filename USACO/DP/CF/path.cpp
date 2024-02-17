#include<bits/stdc++.h>
using namespace std;

int dp[8][8];
int board[8][8];

int main(){

    // freopen("king2.in","r",stdin);
    // freopen("king2.out","w",stdout);
    
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            cin >> board[i][j];
            dp[i][j] = 1e9 + 7;
        }
    }

    dp[7][0] = 0;

    for(int i = 6; i >= 0; --i) dp[i][0] = dp[i + 1][0] + board[i][0];
    for(int i = 1; i < 8; ++i) dp[7][i] = dp[7][i - 1] + board[7][i];

    for(int i = 6; i >= 0; --i){
        for(int j = 1; j < 8; ++j){
            dp[i][j] = board[i][j] + min({dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1]});
        }
    }

    cout << dp[0][7] << '\n';


    return 0;
}