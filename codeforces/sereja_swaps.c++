#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e3 + 7;
const ll inf = -1 * 1e8;
ll n, high = inf, beg = -1, last = -1;
ll largest = inf, pos1 = inf, pos2 = inf, smallest = inf;


vector<ll> a(N);

int find_min(int first, int last){
    for(int i = first; i <= last; ++i){
        if(a[i] < smallest){
            smallest = a[i];
            pos2 = i;
        }
    }
    if(smallest == -1 * inf) return -1;
    return 1;
}

int find_max(int first, int last){
    for(int i = first; i <= last; ++i){
        if(a[i] > largest){
            largest = a[i];
            pos1 = i;
        }
    }
    if(largest == inf) return -1;
    return 1;
}

void sub(){
    for(int i = 0; i < a.size(); ++i){
        for(int j = i + 1; j <= a.size(); ++j){
            ll sum = 0, start = i, stop = j - 1;

            for(int k = i; k < j; ++k) sum += a[k];

            if(sum > high){
                high = sum;
                beg = start;
                last = stop;
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); std::cout.tie(0);

    int k; cin >> n >> k;

    a.resize(n);

    for(int i = 0; i < n; ++i) cin >> a[i];

    sub();


    if(beg == 0 && last == n - 1){

        if(k > 0){
            const auto idx = distance(&a[0], min_element(&a[beg], &a[last]));
            int elt = *min_element(&a[beg], &a[last]);

            if(elt < 0){
                a[idx] = 0;
                k--;
            }
        }


        for(int i = 0; i < k; ++i){
            sub();

            const auto idx = distance(&a[0], min_element(&a[beg], &a[last]));
            int elt = *min_element(&a[beg], &a[last]);

            if(elt < 0){
                a[idx] = 0;
            }
        }

    } else{

        for(int i = 0; i < k; ++i){
            sub();
            ll small = -1, large = -1;

            smallest = -1 * inf, pos1 = inf;

            if(find_min(beg, last) != -1){
                small = smallest;
            };

            largest = inf; pos2 = inf;

            if(find_max(0, beg - 1) != -1){
                large = largest;
            }
            
            if(find_max(last + 1, n - 1) != -1){
                large = max(large, largest);
            }

            if(large > small && (pos1 < n && pos1 >= 0) && (pos2 < n && pos2 >= 0)){
                a[pos2] = large;
                a[pos1] = inf;
            }

        }

    }

    sub();
    
    cout << high << '\n';


    return 0;
}