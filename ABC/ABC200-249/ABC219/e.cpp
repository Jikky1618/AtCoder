#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

struct UnionFind {
    int n, counter;
    vector<int> data;
    UnionFind(int size) : n(size), counter(size), data(size, -1) {}
    int root(int x) { return (data[x] < 0 ? x : data[x] = root(data[x])); }
    bool same(int x, int y) { return root(x) == root(y); }
    bool merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false;
        if (-data[x] < -data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        counter--;
        return true;
    }
    int size(int x) { return -data[root(x)]; }
    int size() { return counter; }
    vector<int> group(int x) {
        vector<int> res;
        for(int i = 0; i < n; i++) if(same(x, i)) res.emplace_back(i);
        return res;
    }
    vector<vector<int>> groups() {
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++) res[root(i)].emplace_back(i);
        res.erase(remove_if(res.begin(), res.end(), [&](const vector<int>& v) {
            return v.empty();
        }), res.end());
        return res;
    }
};

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    const int N = 4, N2 = 6;
    vector A(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }

    // 囲むマスを bit 全探索
    const int M = 16, M2 = 36;
    int ans = 0;
    for(int bit = 0; bit < (1 << M); bit++){
        // B[i][j] := (i, j) を囲うかどうか
        // 外周 1 マスを追加しておく
        // r1 := 囲うマスの 1 つ, r2 := 囲わないマスの 1 つ
        int r1 = 0, r2 = 0;
        vector B(N2, vector<bool>(N2));
        for(int i = 0; i < M; i++){
            if((bit >> i) & 1){
                int x = i / N + 1, y = i % N + 1;
                B[x][y] = true, r1 = x * N2 + y;
            }
        }
        // 囲うマスに家が全て入っているか判定
        bool ok = true;
        for(int x = 0; x < N; x++){
            for(int y = 0; y < N; y++) if(A[x][y] && !B[x + 1][y + 1]) ok = false;
        }
        if(!ok) continue;

        UnionFind uf(M2);
        for(int i = 0; i < M2; i++){
            int x = i / N2, y = i % N2;
            // (x, y) の周囲 4 マスで同じものを連結
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(nx < 0 || nx >= N2 || ny < 0 || ny >= N2) continue;
                if(B[x][y] == B[nx][ny]) uf.merge(i, nx * N2 + ny);
            }
        }
        // 囲うマス, 囲わないマスがそれぞれ全て連結なら ans を加算
        if(uf.size(r1) + uf.size(r2) == M2) ans++;
    }

    cout << ans << '\n';
}