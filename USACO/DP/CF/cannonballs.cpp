#include <bits/stdc++.h>
using namespace std;

const int inf = 4e5 + 8;
int ans[inf];
int r = 1, c = 1, p = 1;

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

int main(){
    freopen("balls.in","r",stdin);
    freopen("balls.out","w",stdout);

    vector<int> pyramids;
    while(p <= inf){
        pyramids.push_back(p);
        r++;
        c += r;
        p += c;
    }
    
    for(int i = 0; i < inf; ++i) ans[i] = inf;
    ans[0] = 0;
    for(int i = 1; i < inf; ++i){
        for(int pyramid: pyramids){
            if(ans[i] == 1) break;
            if(pyramid <= i){
                ans[i] = min(ans[i], ans[i - pyramid] + 1);
            } else{
                break;
            }
        }
    }

    const auto testcases = ReadArray();

    for(const auto t : testcases) cout << ans[t] << '\n';

    return 0;
}

template <typename T>
std::vector<T> ReadArray(int size, std::istream& in_stream) {
  if (!size) {
    in_stream >> size;
  }
  std::vector<T> array(size);
  for (auto& element : array) {
    in_stream >> element;
  }
  return array;
}