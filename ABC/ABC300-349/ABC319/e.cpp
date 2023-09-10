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
    int N;
    ll X, Y;
    cin >> N >> X >> Y;
    vector<ll> P(N - 1), T(N - 1);
    for(int i = 0; i < N - 1; i++) cin >> P[i] >> T[i];

    // 各バス停は P[i] 分ごとにバスが来る
    // LCM ごとにバスが来る時間が一致する -> LCM で周期？ -> 実験で正しそうと判断
    // P の LCM を求める
    ll L = 1;
    for(int i = 0; i < N - 1; i++) L = lcm(L, P[i]);

    vector<ll> ans(L);
    // 時刻 i でスタートしたときの最も早い時間を前計算
    for(int i = 0; i < L; i++){
        ll now = i + X;
        for(int j = 0; j < N - 1; j++){
            if(now % P[j] == 0) now += T[j];
            else now += (P[j] - (now % P[j])) + T[j];
        }
        now += Y;
        ans[i] = now - i;
    }

    int Q;
    cin >> Q;
    while(Q--){
        ll q; cin >> q;
        ll mod = q % L;
        ll time = q + ans[mod];
        cout << time << '\n';
    }
}