#include <bits/stdc++.h>
#define ll long long
#define ld long double 
using namespace std;



main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt; cin >> tt;
    for(int x = 1; x<=tt; ++x){
        int r, c, cnt=0, trees=0; cin >> r >> c;
        char arr[r][c];
        for(int i=0; i<r; ++i){
            for(int j=0; j<c; j++){
                cin >> arr[i][j];
                if(arr[i][j]=='^'){
                    cnt++;
                }
            }
        }
            for(int i=0; i<r; ++i){
                for(int j=0; j<c; ++j){
                    int curr=0;
                    if(arr[i][j]=='^'){
                        curr = 0;
                        if((i-1>=0) && (arr[i-1][j]!='#')){
                            arr[i-1][j]='^';
                            curr++;
                        }
                        if((i+1<r) && (arr[i+1][j]!='#')){
                            arr[i+1][j]='^';
                            curr++;
                        }
                        if((j-1>=0) && (arr[i][j-1]!='#')){
                            arr[i][j-1]='^';
                            curr++;
                        }
                        if((j+1<c) && (arr[i][j+1]!='#')){
                            arr[i][j+1]='^';
                            curr++;
                        }
                    }
                    if(curr>1){
                        trees++;
                    }
                }
            }
        
        if(cnt==0){
            cout << "Case #" << x << ": Possible" << "\n";
            for(int i=0; i<r; ++i){
                for(int j=0; j<c; ++j){
                    cout << arr[i][j];
                }
                cout << "\n";
            }
        }
        else{
        if(r<2 || c<2){
            cout << "Case #" << x << ": Impossible" << "\n";
        }
        else{
        if(trees>=cnt){
            cout << "Case #" << x << ": Possible" << "\n";
            for(int i=0; i<r; ++i){
                for(int j=0; j<c; ++j){
                    cout << arr[i][j];
                }
                cout << "\n";
            }
        }
        else{
            cout << "Case #" << x << ": Impossible" << "\n";
        }
    }
    }
    }

    return 0;

}