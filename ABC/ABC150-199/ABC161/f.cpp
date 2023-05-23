#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// xの約数を列挙した配列を返す
vector<ll> make_is_divisors(ll x){
    vector<ll> divisors;
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            divisors.push_back(i);
            if(x / i != i) divisors.push_back(x / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    set<ll> st;
    auto div = make_is_divisors(N);
    for(auto K: div){
        ll M = N;
        if(K < 2) continue;
        while(M % K == 0) M /= K;
        if(M % K == 1) st.insert(K);
    }

    auto div2 = make_is_divisors(N - 1);
    for(auto d: div2){
        ll K = (N - 1) / d;
        if(K >= 2) st.insert(K);
    }

    cout << st.size() << endl;
}