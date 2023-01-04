#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, K;
    cin >> N >> K;
    vector<ll> P(N), C(N);
    for(int i = 0; i < N; i++) cin >> P[i], P[i]--;
    for(int i = 0; i < N; i++) cin >> C[i];

    ll ans = -INF;
    // マスiからスタートする場合を全探索
    for(int i = 0; i < N; i++){
        ll pos = i, loop_sum = 0, loop_cnt = 0;
        // サイクルの合計, 回数を求める
        while(1){
            loop_cnt++;
            loop_sum += C[pos];
            pos = P[pos];
            if(pos == i) break;
        }

        // サイクルを目一杯回った後の余りの最大を調べる
        // path_sum := スタート位置からの合計スコア
        ll path_sum = 0, cnt = 0;
        while(1){
            cnt++;
            path_sum += C[pos];

            if(cnt > K) break;

            // num := cntまで進んだとき、サイクルを目一杯回れる回数
            ll num = (K - cnt) / loop_cnt;
            ll score = path_sum + max(0LL, loop_sum) * num;
            ans = max(ans, score);

            pos = P[pos];
            if(pos == i) break;
        }
    }

    cout << ans << endl;
    return 0;
}