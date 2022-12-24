#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    char pres;
    ll x, y, count=0; cin >> x >> y >> pres;
    vector<char> deputies('/'); 
    vector < pair <int, int> > pres_cords;
    char arr[x][y];
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            cin >> arr[i][j];
            if(arr[i][j]==pres){
                pres_cords.push_back(make_pair(i, j));
            }
        }
    }

    
    for(pair coordinate: pres_cords){
        if(coordinate.first-1>=0){
        
        if((arr[coordinate.first-1][coordinate.second]!='.')&&(arr[coordinate.first-1][coordinate.second]!=pres)&&(arr[coordinate.first-1][coordinate.second]!=deputies[1])){
            count++;
            deputies[1]=(arr[coordinate.first-1][coordinate.second]);
        }
        }

        if(coordinate.first+1<x){
            
        if((arr[coordinate.first+1][coordinate.second]!='.')&&(arr[coordinate.first+1][coordinate.second]!=pres)&&(arr[coordinate.first+1][coordinate.second]!=deputies[0])){
            count++;
            deputies[0]=(arr[coordinate.first+1][coordinate.second]);
        }
        }
        if(coordinate.second+1<y){
        if((arr[coordinate.first][coordinate.second+1]!='.')&&(arr[coordinate.first][coordinate.second+1]!=pres)&&(arr[coordinate.first][coordinate.second+1]!=deputies[2])){
            count++;
            deputies[2]=(arr[coordinate.first][coordinate.second+1]);
        }
        }
        if(coordinate.second-1>=0){
        if((arr[coordinate.first][coordinate.second-1]!='.')&&(arr[coordinate.first][coordinate.second-1]!=pres)&&(arr[coordinate.first][coordinate.second-1]!=deputies[3])){
            count++;
            deputies[3]=(arr[coordinate.first][coordinate.second-1]);
        }
        }
    }

cout << count << endl;


    return 0;
}