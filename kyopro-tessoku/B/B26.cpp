#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// エラトラネスの篩で N 以下の素数を求める
vector<bool> make_is_prime(int N) {
    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= N; j += i) {
            prime[j] = false;
        }
    }
    return prime;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    auto p = make_is_prime(N);
    for(int i = 1; i <= N; i++){
        if(p[i]) cout << i << '\n';
    }
}