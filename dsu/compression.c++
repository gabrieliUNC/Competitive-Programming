#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 7;

int raw[mxN];
unordered_map<int, int> mp, rmp;


int main(){
    int idx = 0;
    for (auto c : raw){
        mp[c] = idx;
        rmp[idx] = c;
        idx++;
    }
    /*
    value = queries[i]; //queries already compressed
    raw_value = rmp[value];
    int left_raw_value = raw_value - 1;

    if (mp.find(left_raw_value) != mp.end()) {
        int compressed_left = mp[left_raw_value];
        union(value, compressed_left);
    }
    
    */
}