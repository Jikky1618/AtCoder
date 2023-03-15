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
    int R, C, K, N;
    cin >> R >> C >> K >> N;
    vector<int> r(N), c(N);
    for(int i = 0; i < N; i++) cin >> r[i] >> c[i], r[i]--, c[i]--;

    // 各行各列の飴マスの個数を前計算
    vector<int> Row(R), Column(C);
    for(int i = 0; i < N; i++){
        Row[r[i]]++, Column[c[i]]++;
    }

    // 飴マスの個数がi個である各行各列の数を計算
    map<int, ll> mpr, mpc;
    for(int i = 0; i < R; i++) mpr[Row[i]]++;
    for(int i = 0; i < C; i++) mpc[Column[i]]++;

    ll ans = 0;
    // 和がK個になるマス数を求める
    for(int i = 0; i <= K; i++){
        ans += mpc[i] * mpr[K - i];
    }

    for(int i = 0; i < N; i++){
        // 起点に飴があり、和がK個となるマス数だけ引く
        if(Row[r[i]] + Column[c[i]] == K) ans--;
        // 起点に飴があり、和がK+1個となるマス数だけ足す
        if(Row[r[i]] + Column[c[i]] == K + 1) ans++;
    }

    cout << ans << endl;
}