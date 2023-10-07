#include <bits/stdc++.h>
using namespace std;


int solve(){
    string s; cin >> s;
    int sum = 0;
    for(int i = 0; i < 3; ++i){ 
        int temp = (int) s[i] - '0';
        sum += temp;
    }
    for(int i = 3; i < 6; ++i){ 
        int temp = (int) s[i] - '0'; 
        sum -= temp;
    }
    if(sum == 0) return 0;
    if(sum < 0){
        //put all x into minheap to try to maximize
        //put all y into maxheap to try to minimize

        priority_queue<int, vector<int>, greater<int>> x;
        priority_queue<int> y;

        for(int i = 0; i < 3; ++i){ 
            int temp = (int) s[i] - '0';
            x.push(temp);
        }
        for(int i = 3; i < 6; ++i){ 
            int temp = (int) s[i] - '0'; 
            y.push(temp);
        }
        for(int i = 0; i < 3; ++i){
            // cout << 'x' << x.top() << 'y' << y.top() << '\n';
            if((9 - x.top()) > y.top()){
                sum += 9 - x.top();
                x.pop();
            } else{
                sum += y.top();
                y.pop();
            }
            if(sum >= 0) return i + 1;
        }
    } else{
        //do the opposite

        priority_queue<int> x;
        priority_queue<int, vector<int>, greater<int>> y;

        for(int i = 0; i < 3; ++i){ 
            int temp = (int) s[i] - '0';
            x.push(temp);
        }
        for(int i = 3; i < 6; ++i){ 
            int temp = (int) s[i] - '0'; 
            y.push(temp);
        }
        for(int i = 0; i < 3; ++i){
            // cout << 'x' << x.top() << 'y' << y.top() << '\n';
            if((x.top()) > 9 - y.top()){
                sum -= x.top();
                x.pop();
            } else{
                sum -= 9 - y.top();
                y.pop();
            }
            if(sum <= 0) return i + 1;
        }
    }
    return 3;
}
int main(){
    
    cout << solve() << '\n';

    return 0;
}