#include <bits/stdc++.h>
#define ll long long
using namespace std;

template <typename T>struct is_basic_string : std::false_type {};
template <typename CharT, typename Traits, typename Alloc>struct is_basic_string<std::basic_string<CharT, Traits, Alloc>> : std::true_type {};
template <typename T, typename = void>struct has_begin_end : std::false_type {};
template <typename T>struct has_begin_end<T, std::void_t<decltype(std::begin(std::declval<T&>())), decltype(std::end(std::declval<T&>()))>> : std::true_type {};
template <typename Tuple, std::size_t... Indices>void print_tuple_impl(std::ostream& os, const Tuple& t, std::index_sequence<Indices...>) {((os << (Indices == 0 ? "" : ", ") << std::get<Indices>(t)), ...);}
template<typename... T> ostream& operator<<(ostream& os,  const std::tuple<T...>&& v){os << "{"; print_tuple_impl(os, v, std::index_sequence_for<T...>{}); os << "}"; return os;}
template<typename... T> ostream& operator<<(ostream& os,  const std::tuple<T...>& v){os << "{"; print_tuple_impl(os, v, std::index_sequence_for<T...>{}); os << "}"; return os;}
template<typename T, typename K> ostream& operator<<(ostream& os,  const std::pair<T, K>&& v){os << "{"; os << v.first << ", " << v.second; os << "}"; return os;}
template<typename T, typename K> ostream& operator<<(ostream& os,  const std::pair<T, K>& v){os << "{"; os << v.first << ", " << v.second; os << "}"; return os;}
template<typename... T, template<class> typename C> ostream& operator<<(ostream& os,  const C<std::tuple<T...>>& v){os << "{"; if (v.size()>0) {auto en = v.end(); en = std::prev(en, 1); for (auto it = v.begin(); it != v.end(); it=std::advance(it,1)){ os << "{"; print_tuple_impl(os,*it, std::index_sequence_for<T...>{}); os << "}"; if (it != en) {os << ", ";} }} os << "}"; return os;}
template<typename... T, template<class> typename C> ostream& operator<<(ostream& os,  const C<std::tuple<T...>>&& v){os << "{"; if (v.size()>0){auto en = v.end(); en = std::prev(en, 1); for (auto it = v.begin(); it != v.end(); it=std::advance(it,1)){ os << "{"; print_tuple_impl(os,*it, std::index_sequence_for<T...>{}); os << "}"; if (it != en) {os << ", ";} }} os << "}"; return os;}
template<typename... T,template<class...> class V,typename std::enable_if<!is_basic_string<V<T...>>::value>::type* = nullptr>std::ostream& operator<<(std::ostream& os,  const V<T...>& v){os << "{";if (v.size() > 0) {std::size_t en = v.size();--en; std::size_t ii = 0; for (auto it = v.begin(); it != v.end(); ++it, ii++) {os << (*it);if (ii != en) {os << ", ";}}}os << "}";return os;}
template<typename... T,template<class...> class V,typename std::enable_if<!is_basic_string<V<T...>>::value>::type* = nullptr>std::ostream& operator<<(std::ostream& os,  const V<T...>&& v){os << "{";if (v.size() > 0){std::size_t en = v.size();--en; std::size_t ii = 0;for (auto it = v.begin(); it != v.end(); ++it, ii++) {os << (*it);if (ii != en) {os << ", ";}}}os << "}";return os;}
template<std::size_t XX, typename T,template<class, std::size_t> class V,typename std::enable_if<!is_basic_string<V<T, XX>>::value>::type* = nullptr>std::ostream& operator<<(std::ostream& os,  const V<T, XX>& v){os << "{";if (v.size() > 0) {std::size_t en = v.size();--en; std::size_t ii = 0; for (auto it = v.begin(); it != v.end(); ++it, ii++) {os << (*it);if (ii != en) {os << ", ";}}}os << "}";return os;}
template<std::size_t XX, typename T,template<class, std::size_t> class V,typename std::enable_if<!is_basic_string<V<T, XX>>::value>::type* = nullptr>std::ostream& operator<<(std::ostream& os,  const V<T, XX>&& v){os << "{";if (v.size() > 0) {std::size_t en = v.size();--en; std::size_t ii = 0; for (auto it = v.begin(); it != v.end(); ++it, ii++) {os << (*it);if (ii != en) {os << ", ";}}}os << "}";return os;}
template<typename T,template<class...> class V,typename std::enable_if<has_begin_end<V<T>>::value && !is_basic_string<V<T>>::value>::type* = nullptr>std::istream& operator>>(std::istream& is, V<T>& v) {for (auto it = std::begin(v); it != std::end(v); ++it) {is >> *it;}return is;}

int main() {
    int n, k; cin >> n >> k;
    vector<int> A(n);
    cin >> A;
    // cout << A;

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

    for(auto num : A) pq.push({0, (ll) num});

    while(n) {
        vector<pair<ll, ll>> drivers;
        for(int i = 0; i < k; ++i) {
            drivers.push_back(pq.top());
            pq.pop();
        }

        for(auto& [time, cost] : drivers) {
            
        }
    }

    



    return 0;
}