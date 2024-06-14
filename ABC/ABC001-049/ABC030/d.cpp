#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, a;
    string k;
    cin >> N >> a >> k, a--;
    vector<int> b(N);
    for (int i = 0; i < N; i++) cin >> b[i], b[i]--;

    // とりあえず, 閉路上の頂点に到達する
    int pos = a;
    vector<int> seen(N);
    while(seen[pos] != 1) {
        seen[pos] = 1;
        pos = b[pos];
    }
    // 閉路上の点を求める
    while(seen[pos] != 2) {
        seen[pos] = 2;
        pos = b[pos];
    }

    // サイクルまでに到達する長さ, 閉路の長さを求める
    int path_len = 0, cycle_len = 0;
    for(int i = 0; i < N; i++) {
        if(seen[i] == 1) path_len++;
        if(seen[i] == 2) cycle_len++;
    }

    // パス上の頂点 < N 回以内で到達できる頂点の場合
    if(k.size() <= 6 && stoi(k) <= N) {
        int ans_cnt = stoi(k), ans = a;
        for(int i = 0; i < ans_cnt; i++) ans = b[ans];
        cout << ans + 1 << '\n';
        return 0;
    }

    // 閉路上の頂点の場合
    // 求める位置は a から初めて到達するサイクル上の点 ( = pos) から (k - path_len) % cycle_len 個先の頂点
    // = k % cycle_len - path_len % cycle_len
    int modk = 0;
    for(auto c: k) {
        modk = (modk * 10 + (c - '0')) % cycle_len;
    }
    int ans_cnt = modk - (path_len % cycle_len);
    if(ans_cnt < 0) ans_cnt += cycle_len;

    int ans = pos;
    debug(pos, path_len, cycle_len);
    for(int i = 0; i < ans_cnt; i++) ans = b[ans];

    cout << ans + 1 << '\n';
}