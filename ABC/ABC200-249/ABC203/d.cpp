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
    int N, K;
    cin >> N >> K;
    vector A(N, vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }
    // 中央値の最小を二分探索
    // すべての区画の中央値が mid 以上か
    // mid 以上の値がすべての区画に k^2 / 2 個以上存在するか
    auto check = [&](ll mid) -> bool {
        // B[i][j] := 値が mid 以上かどうか(true, false)
        vector B(N, vector<int>(N));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++) B[i][j] = (A[i][j] >= mid);
        }
        debug(mid, B);

        // B の二次元累積和
        vector acc(N + 1, vector<int>(N + 1));
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                acc[i + 1][j + 1] = acc[i][j + 1] + acc[i + 1][j] - acc[i][j] + B[i][j];
            }
        }
        debug(acc);
        // flag := すべての区画の中央値が mid 以上か
        bool flag = true;
        for(int i = 0; i <= N - K; i++){
            for(int j = 0; j <= N - K; j++){
                int a = i, b = j, c = i + K, d = j + K;
                ll val = acc[c][d] - acc[a][d] - acc[c][b] + acc[a][b];
                debug(val);
                // mid 以上の値が K^2 / 2 + 1 個未満のとき、中央値は mid 未満
                if(val < (K * K / 2) + 1) flag = false;
            }
        }
        return flag;
    };

    ll ok = 0, ng = 1e9 + 1;
    while(ng - ok > 1){
        int mid = (ok + ng) / 2;
        check(mid) ? ok = mid : ng = mid;
    }

    debug(ok, ng);
    cout << ok << endl;
}