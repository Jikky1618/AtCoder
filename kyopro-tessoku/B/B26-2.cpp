#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<int> make_is_prime(int N) {
    vector<bool> prime(N + 1, true);
    prime[0] = prime[1] = false;
    vector<int> res;
    int i = 2;
    for (; i * i <= N; i++) {
        if (!prime[i]) continue;
        res.emplace_back(i);
        for (int j = i * i; j <= N; j += i) {
            prime[j] = false;
        }
    }
    for(; i <= N; i++) {
        if(!prime[i]) continue;
        res.emplace_back(i);
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    auto p = make_is_prime(N);
    for(unsigned i = 0; i < p.size(); i++){
        cout << p[i] << '\n';
    }
}