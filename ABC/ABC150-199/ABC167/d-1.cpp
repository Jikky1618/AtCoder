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
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;

    // 周期性を利用
    // サイクルを検出する
    vector<int> flag(N);
    int pos = 0, cnt = 1;
    while(1){
        if(flag[pos] != 0) break;
        flag[pos] = cnt, cnt++;
        pos = A[pos];
    }

    // 1 サイクルあたりの移動回数を求める
    ll loop_cnt = 0, loop_end = pos;
    while(1){
        if(loop_cnt != 0 && pos == loop_end) break;
        loop_cnt++;
        pos = A[pos];
    }

    // スタート -> サイクルまでの移動回数を求める
    pos = 0, cnt = 0;
    while(1){
        if(pos == loop_end || cnt == K) break;
        cnt++;
        pos = A[pos];
    }
    
    // サイクル分を飛ばす
    // ll cycle_cnt = (K - cnt) / loop_cnt;
    ll remain = (K - cnt) % loop_cnt;
    while(remain--){
        pos = A[pos];
    }

    cout << pos + 1 << endl;
}