#include <bits/stdc++.h>
#define ll long long
using namespace std;

main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        int n, x, y, comp = 0, start = 0; cin >> n >> x >> y;
        int dif = y - x;
        int i=1;
        while (i!=n){
            int count = (dif%(n-i));
            comp = (dif/(n-i));
            if (count==0){
                if((x-comp)>0){
                    int j = 1;
                    start = (x);
                    while(x-(comp*j)>0){
                        start-=comp;
                        j++;
                    }
                    break;
                }
            }
            i++;
        }
        if(start!=0){
        while(y>(start+(comp*(n-1)))){
            start+=comp;
        }
        

        i = 0;
        while(i!=n){
            cout << start + (comp*i) << "\n";
            i++;
        }
        }
        else{
            i = 0;
            while(i!=n){
                cout << x + (comp*i) << "\n";
                i+=1;
            }
        }
    }



    return 0;
}