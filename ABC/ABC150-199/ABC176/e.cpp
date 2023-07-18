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
    int H, W, M;
    cin >> H >> W >> M;
    vector<int> h(M), w(M);
    for(int i = 0; i < M; i++) cin >> h[i] >> w[i], h[i]--, w[i]--;

    // r[i] := i行目にある爆弾数, c[i] := i列目にある爆弾数
    vector<int> r(H), c(W);
    for(int i = 0; i < M; i++){
        r[h[i]]++, c[w[i]]++;
    }

    // 行, 列の最大の爆弾数を求める
    int mx = *max_element(r.begin(), r.end()), my = *max_element(c.begin(), c.end());

    // 最大の爆弾数のある行, 列を X, Y に入れる
    vector<int> X, Y;
    for(int i = 0; i < H; i++) if(r[i] == mx) X.emplace_back(i);
    for(int i = 0; i < W; i++) if(c[i] == my) Y.emplace_back(i);

    // 爆弾リスト
    set<pair<int, int>> bomb;
    for(int i = 0; i < M; i++) bomb.insert({h[i], w[i]});

    // X, Y を全探索
    for(auto x: X){
        for(auto y: Y){
            if(!bomb.count({x, y})){
                cout << mx + my << endl;
                return 0;
            }
        }
    }

    cout << mx + my - 1 << endl;
}