#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    ll houses, tasks, new_house = 0, cur_house = 1, turns=0; cin >> houses >> tasks;
    for(int i=0; i<tasks; i++){
        cin >> new_house;
        if(new_house >= cur_house){
            turns += (new_house-cur_house);
            cur_house = new_house;
        }
        else{
            turns += ((houses-cur_house) + new_house);
            cur_house = new_house;
        }
    }

cout << turns << endl;


    return 0;
}