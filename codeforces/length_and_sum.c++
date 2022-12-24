#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
    vector<int> min;
    vector<int> max;
    min.push_back(s);
    

    while(min.back()>9){
        min.insert(min.begin(), 9);
        min.back()-=9;
    }

    for(auto e = min.end(); e!=min.begin(); --e){
        //
    }



    return 0;
}