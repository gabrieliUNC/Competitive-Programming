#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ull unsigned long long
#define ld long double

#define sz(x) (int)x.size()
template<typename FUNCTION>
#define loop(x,n) for(int x = 0; x < n; ++x)
#define loopd(x, n) for(int x = n; x>=0; --x)
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define START ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);                                                            
#define CPU cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s." << endl;
#define vi vector<int>;
#define vvi vector<vi>;
#define pii pair<int, int>;
#define vpii vector<pii>;

const int MOD = 1e9 + 7;
const ll inf = 1e18 + 5;
const ld pi = atan(1)*4;
const int maxn = 1e5 + 5;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T> using ordered_tree = tree< T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> class MinSegmentTree {
  private:
	const T DEFAULT = 1e18;  // Will overflow if T is an int

	vector<T> segtree;
	int len;

  public:
	MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	/** Sets the value at ind to val. */
	void set(int ind, T val) {
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
		}
	}

	/** @return the op element in the range [start, end) */
	T range_min(int start, int end) {
		T op = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { op = std::min(op, segtree[start++]); }
			if (end % 2 == 1) { op = std::min(op, segtree[--end]); }
		}
		return op;
	}
};

string Alice(int height, int width, int x_alice, int x_bob, int y_alice, int y_bob){
    // Alice Chases
        while(x_alice < height && x_bob > 0){

            // Passed Pawn
            if(x_alice >= x_bob) return "Draw\n";

            // Alice
            if(y_alice == y_bob){ // go up
                x_alice++;
            }
            else if(y_alice < y_bob && y_alice < width){ // go right
                x_alice++;
                y_alice++;    
            }

            else if(y_alice > y_bob && y_alice > 1){ // go left
                x_alice++;
                y_alice--;
            }

            else { // hit a wall
                x_alice++;
            }


            if(x_alice == x_bob && y_alice == y_bob) return "Alice\n";


            // Bob
            if(y_bob <= y_alice && y_bob > 1){ // go left
                x_bob--;
                y_bob--;
            }
            else if(y_bob < width && y_bob >= y_alice){ // go right
                x_bob--;
                y_bob++;
            } else{ // go down
                x_bob--;
            }

            if(x_alice == x_bob && y_alice == y_bob) return "Bob\n";
        }
        return "Draw\n";
}

string Bob(int height, int width, int x_alice, int x_bob, int y_alice, int y_bob){
        // Bob Chases
        while(x_alice < height && x_bob > 0){
            // cout << x_alice << ' ' << y_alice << '\n';
            // cout << x_bob << ' ' << y_bob << '\n';

            // Passed Pawn
            if(x_alice >= x_bob) return "Draw\n";
            
            // Alice
            if(y_alice <= y_bob && y_alice > 1){ // go left
                x_alice++;
                y_alice--;
            } else if(y_alice < width && y_alice >= y_bob){ // go right
                x_alice++;
                y_alice++;
            } else{ // go up
                x_alice++;
            }


            if(x_alice == x_bob && y_alice == y_bob) return "Alice\n";

            // Bob
            if(y_bob == y_alice){ // go down
                y_bob--;
            }
            else if(y_bob < y_alice && y_bob < width){ // go right
                x_bob--;
                y_bob++;    
            }

            else if(y_bob > y_alice){ // go left
                x_bob--;
                y_bob--;
            }

            else { // hit a wall
                x_bob--;
            }

            if(x_alice == x_bob && y_alice == y_bob) return "Bob\n";
        }
        return "Draw\n";
}


string solve(){
    int height, width, x_alice, x_bob, y_alice, y_bob; cin >> height >> width >> x_alice >> y_alice >> x_bob >> y_bob;


    string a = Alice(height, width, x_alice, x_bob, y_alice, y_bob), b = Bob(height, width, x_alice, x_bob, y_alice, y_bob);

    if(a == "Draw\n") return b;
    return a;
    
}

int main(){
    START
    
    int t; cin >> t;
    while(t--){
        
        cout << solve();

        
    }



    return 0;
}

                                 
