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
    ll N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 周期性を利用
    // サイクルを検出する
    vector<int> flag(N);
    ll X = 0, pos = 0, cnt = 1;
    while(1){
        if(flag[pos] != 0) break;
        flag[pos] = cnt, cnt++;
        X += A[pos], pos = X % N;
    }

    // 1 サイクルあたりの移動回数を求める
    ll loop_cnt = 0, loop_sum = 0, loop_end = pos;
    while(1){
        if(loop_cnt != 0 && loop_end == pos) break;
        loop_cnt++, loop_sum += A[pos];
        X += A[pos], pos = X % N;
    }

    // スタート -> サイクルまでの移動回数を求める
    X = 0, pos = 0, cnt = 0;
    while(1){
        if(pos == loop_end || cnt == K) break;
        X += A[pos], cnt++;
        pos = X % N;
    }

    // サイクル分を飛ばす
    ll cycle_cnt = (K - cnt) / loop_cnt, remain = (K - cnt) % loop_cnt;
    X += cycle_cnt * loop_sum;
    while(remain--){
        X += A[pos];
        pos = X % N;
    }

    debug(loop_cnt, loop_sum, loop_end, cycle_cnt, remain);
    cout << X << endl;
}