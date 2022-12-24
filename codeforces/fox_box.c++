#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, ans=1; cin >> n;
    priority_queue<int> pq;
    int zero = 0;
    while(n--){int temp; cin >> temp; if(temp==0){zero++;} else{pq.push(temp);}}
    if(pq.size()>1){
    stack <int> containers;
    int curr = pq.top();
    pq.pop();
    int boxes = pq.size();
    boxes -= curr;
    containers.push(curr);
    while(boxes>0){
        curr = pq.top();
        pq.pop();
        boxes-=curr+1;
        containers.push(curr);
    }
    int original = containers.size();
    int bottom = containers.top();
    containers.pop();
    curr = pq.top();
    pq.pop();
    int size = 0;
    while(pq.size()){
        if(bottom < size){ans++; size = 0; bottom = containers.top(); containers.pop(); curr = pq.top();}
            size++;
            curr = pq.top();
            pq.pop();
        }
        boxes*=-1;
        ans = ans > original ? ans : original;
        zero = boxes>=1 ? zero-1: 0;
        if(zero>=0){
        ans+=zero;
    }
    }
    else{
        zero-=ans;
        ans+=zero;
    }
    
 
    cout << ans;
 
 
    return 0;
}