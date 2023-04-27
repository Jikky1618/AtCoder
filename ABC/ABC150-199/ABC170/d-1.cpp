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
vector<ll> make_is_divisors(ll x, bool sorted = true){
    vector<ll> divisors;
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            divisors.push_back(i);
            if(x / i != i) divisors.push_back(x / i);
        }
    }
    if(sorted) sort(divisors.begin(), divisors.end());
    return divisors;
}

constexpr int MAX = 1e6 + 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> cnt(MAX);
    for(int i = 0; i < N; i++) cnt[A[i]]++;

    int ans = 0;
    for(int i = 0; i < N; i++){
        auto div = make_is_divisors(A[i], false);
        bool flag = false;
        for(auto e: div){
            // 約数 = A[i]のとき
            if(e == A[i] && 2 <= cnt[e]){
                flag = true;
                break;
            }
            // 約数 != A[i]のとき
            if(e != A[i] && 1 <= cnt[e]){
                flag = true;
                break;
            }
        }
        if(flag == false) ans++;
        debug(div, flag);
    }

    cout << ans << endl;
}