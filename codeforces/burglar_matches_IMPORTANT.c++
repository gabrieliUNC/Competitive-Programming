#include <bits/stdc++.h>
#include <iostream>
#include <map>
#define ll long long
using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int,int> &b){
        return a.second>b.second;
    }

main(){
    ll rucksack, matchboxes; cin>>rucksack >> matchboxes;
    pair<ll int , ll int>map[100];
    for(ll i=0; i<matchboxes; i++){
        cin >> map[i].first >> map[i].second;
    }

    sort(map, map + matchboxes, sortbysec);

    ll count = 0;

    for(int j=0; j<matchboxes; j++){
        if(map[j].first<=rucksack){
            count+=(map[j].first*map[j].second);
            rucksack-=map[j].first;
        }
        else{
            count += rucksack*(map[j].second);
            rucksack = 0;
        }
        if(rucksack<=0){
            break;
        }
    }
    cout << count;
    
}
