#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int naive(int H, int W, vector<vector<int>> A) {
    // 反転させる行を bit 全探索
    int ans = H + 1;
    for (int bit = 0; bit < (1 << H); bit++) {
        auto B(A);
        for (int i = 0; i < H; i++) {
            if (bit >> i & 1) {
                for (int j = 0; j < W; j++) B[i][j] = 1 - B[i][j];
            }
        }
        bool ok = true;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                bool isolate = true;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k], nj = j + dy[k];
                    if (ni < 0 || ni >= H || nj < 0 || nj >= W) continue;
                    if (B[ni][nj] == B[i][j]) isolate = false;
                }
                if (isolate) ok = false;
            }
        }
        if (ok) ans = min(ans, __builtin_popcount(bit));
    }
    return (ans == H + 1 ? -1 : ans);
}

const int INF = (1 << 30) - 1;
int solve(int H, int W, vector<vector<int>> A) {
    // dp[i][j][k] := i 行目まで見て, i - 1 行目を反転させたか(j), i 行目を反転させたか(k) のときの最小操作回数
    vector dp(H + 1, vector(2, vector(2, INF)));
    dp[0][0][0] = 0, dp[0][0][1] = 1;
    for (int i = 0; i < H; i++) {
        // j := i - 1 行目を反転させたか
        for (int j = 0; j < 2; j++) {
            // k := i 行目を反転させたか
            for (int k = 0; k < 2; k++) {
                // l := i + 1 行目を反転させるか
                for(int l = 0; l < 2; l++) {
                    // i 行目について, 独立した要素がないかを見る
                    vector B(3, vector<int>(W, -1));
                    for(int x = 0; x < 3; x++){
                        for(int y = 0; y < W; y++){
                            if(i - 1 >= 0 && x == 0) B[x][y] = (j ? 1 - A[i - 1][y] : A[i - 1][y]);
                            if(x == 1) B[x][y] = (k ? 1 - A[i][y] : A[i][y]);
                            if(i + 1 < H && x == 2) B[x][y] = (l ? 1 - A[i + 1][y] : A[i + 1][y]);
                        }
                    }

                    bool flag = true;
                    for(int y = 0; y < W; y++){
                        bool isolate = true;
                        for(int d = 0; d < 4; d++){
                            int nx = 1 + dx[d], ny = y + dy[d];
                            if(nx < 0 || nx >= 3 || ny < 0 || ny >= W) continue;
                            if(B[nx][ny] == B[1][y]) isolate = false;
                        }
                        if(isolate) flag = false;
                    }

                    // 独立した要素がなければ, 遷移(l によって操作回数が変わる)
                    if(flag){
                        dp[i + 1][k][l] = min(dp[i + 1][k][l], dp[i][j][k] + l);
                    }
                }
            }
        }
    }

    int ans = INF;
    for(int j = 0; j < 2; j++){
        for(int k = 0; k < 2; k++){
            ans = min(ans, dp[H][j][k]);
        }
    }

    return (ans == INF ? -1 : ans);
}

int64_t seed = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
mt19937_64 rnd(seed);
// 閉区間 [l, r] の範囲で乱数を生成
template <class T>
T generate_number(T l, T r) {
    uniform_int_distribution<T> dist(l, r);
    return dist(rnd);
}
// 大きさ N, 要素が閉区間 [l, r] の範囲である配列を生成
template <class T>
vector<T> generate_vector(int N, T l, T r, bool unique = false) {
    vector<T> V(N);
    // 重複ありの場合
    if(!unique) {
        for(int i = 0; i < N; i++) V[i] = generate_number(l, r);
    // 重複なしの場合
    } else {
        unordered_set<T> st;
        int pos = 0;
        while(pos < N) {
            T val = generate_number(l, r);
            if(st.count(val)) continue;
            st.insert(val);
            V[pos++] = val;
        }
    }
    return V;
}

void test() {
    int t; cin >> t;
    while(t--) {
        int H = generate_number(2, 10);
        int W = generate_number(2, 10);
        vector<vector<int>> A(H, vector<int>(W));
        for(int i = 0; i < H; i++) A[i] = generate_vector(W, 0, 1);
        debug(H, W, A);
        if(naive(H, W, A) != solve(H, W, A)) {
            debug(H, W, A);
            debug(naive(H, W, A), solve(H, W, A));
            return;
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    // test();
    int H, W;
    cin >> H >> W;
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }
    cout << solve(H, W, A) << '\n';
}