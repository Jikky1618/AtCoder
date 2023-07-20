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
    ll N, X, M;
    cin >> N >> X >> M;

    ll val = X, cnt = 1;
    vector<int> flag(M + 1);
    while(1){
        if(flag[val] != 0) break;
        flag[val] = cnt, cnt++;
        val *= val, val %= M;
    }

    // サイクル部分の数と総和を求める
    ll loop_cnt = 0, loop_sum = 0, loop_end = val;
    while(1){
        if(loop_cnt != 0 && loop_end == val) break;
        loop_cnt++, loop_sum += val;
        val *= val, val %= M;
    }

    ll ans = 0;
    cnt = 0, val = X;
    // サイクル部分までの総和を求める
    while(1){
        if(val == loop_end || cnt == N) break;
        ans += val, cnt++;
        val *= val, val %= M;
    }

    // サイクル部分の総和を求める
    ll cycle_cnt = (N - cnt) / loop_cnt, remain = (N - cnt) % loop_cnt;
    ans += cycle_cnt * loop_sum;
    // 1周しないサイクル部分の和を求める
    while(remain--){
        ans += val;
        val *= val, val %= M;
    }

    debug(loop_cnt, loop_sum, loop_end, cycle_cnt, remain);
    cout << ans << endl;
}