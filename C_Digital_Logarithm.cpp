#include <bits/stdc++.h>
using namespace std;

int len(int x) {
    return floor(log10(x)) + 1;
}

int solve() {
    int n, ans = 0; cin >> n;

    priority_queue<int> a, b;
    for(int i = 0; i < n; ++i) 
    {
        int tmp; cin >> tmp;
        a.push(tmp);
    }
    for(int i = 0; i < n; ++i) 
    {
        int tmp; cin >> tmp;
        b.push(tmp);
    }

    while(n) {
        auto num1 = a.top(), num2 = b.top();
        a.pop(); b.pop();
        if(num1 > num2) {
            a.push(len(num1));
            b.push(num2);
            ++ans;
        } else if(num2 > num1) {
            a.push(num1);
            b.push(len(num2));
            ++ans;
        } else n--;
    }


    return ans;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tt; cin >> tt;

    while(tt--) cout << solve() << '\n';



    return 0;
}