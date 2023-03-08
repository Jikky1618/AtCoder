#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, A, B;
    cin >> N >> A >> B;

    // 1 ~ Nまでの総和
    auto sum = [&](ll N) -> ll {
        return N * (N + 1) / 2;
    };

    ll all = sum(N);
    ll a = sum(N / A) * A;
    ll b = sum(N / B)* B;
    ll l = sum(N / lcm(A, B)) * lcm(A, B);

    cout << all - a - b + l << endl;
}