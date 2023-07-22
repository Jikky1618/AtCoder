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
    int H, W, N;
    cin >> H >> W >> N;
    vector A(H, vector<int>(W));
    for(int i = 0; i < N; i++){
        int a, b; cin >> a >> b, a--, b--;
        A[a][b] = 1;
    }

    // 二次元累積和
    vector acc(H + 1, vector<int>(W + 1));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            acc[i + 1][j + 1] = acc[i][j + 1] + acc[i + 1][j] - acc[i][j] + A[i][j];
        }
    }
    debug(acc);

    auto check = [&](int i, int j, int mid) -> bool {
        if(i + mid > H || j + mid > W) return false;
        int a = i, b = j, c = i + mid, d = j + mid;
        int val = acc[c][d] - acc[a][d] - acc[c][b] + acc[a][b];
        debug(val);
        return val == 0;
    };

    ll ans = 0;
    // 右上を全探索
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == 1) continue;
            // 正方形の面積の最大を二分探索
            ll ok = 0, ng = min(H - i, W - j) + 1;
            while(ng - ok > 1){
                ll mid = (ok + ng) / 2;
                (check(i, j, mid) ? ok : ng) = mid;
            }
            debug(ok);
            ans += ok;
        }
    }

    cout << ans << endl;
}