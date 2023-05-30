#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    
    // 二分探索 (mid 以下のペアが K 個以上あるかどうか)
    auto check = [&](ll mid) -> bool {
        ll S = 0, T = 0;
        for(int i = 0; i < N; i++){
            // A[i] が正のとき
            if(A[i] > 0){
                // A[i] * A[m] <= mid となる m の個数を二分探索
                int ok = -1, ng = N;
                while(ng - ok > 1){
                    int m = (ok + ng) / 2;
                    if(A[i] * A[m] <= mid) ok = m;
                    else ng = m;
                }
                S += ok + 1;
            // A[i] が負のとき
            }else if(A[i] < 0){
                // A[i] * A[m] <= mid となる m の個数を二分探索
                int ok = N, ng = -1;
                while(ok - ng > 1){
                    int m = (ok + ng) / 2;
                    if(A[i] * A[m] <= mid) ok = m;
                    else ng = m;
                }
                S += N - ok;
            // A[i] = 0 で, mid >= 0 なら, N 個全て当てはまる
            }else if(A[i] == 0 && mid >= 0){
                S += N;
            }
            // A[i] * A[i]の場合を後で引くためにカウント
            if(A[i] * A[i] <= mid) T++;
        }
        // A[i] * A[i]の場合を引き, A[i] * A[j] と A[j] * A[i]が重複しているので2で割る
        ll cnt = (S - T) / 2;
        return cnt >= K;
    };

    // mid 以下のペアが K 個以上ある最小値が答え
    ll ok = INF, ng = -INF;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}