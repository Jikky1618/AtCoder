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
    int T;
    cin >> T;
    while(T--){
        ll N, D, K;
        cin >> N >> D >> K, K--;
        // 0からDずつ進んだとき、初めてDの倍数になる(同じ所に戻る)までの周期回数
        ll A = lcm(N, D) / D;
        // 何周目か
        ll cycle_cnt = K / A;
        // K回目に印をつけるマスはなにか
        ll pos = (K * D) % N;
        // K回目は何周目の何回目になるか
        cout << cycle_cnt + pos << '\n';
    }
}