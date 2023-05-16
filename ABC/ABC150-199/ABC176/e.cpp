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

    // rols[i] := i行目の爆弾対象の数
    // cols[i] := i列目の爆弾対象の数
    vector<int> rows(H), cols(W);
    for(int i = 0; i < M; i++){
        rows[h[i]]++, cols[w[i]]++;
    }

    // 爆弾対象があるかどうかを管理するset
    set<pair<int, int>> st;
    for(int i = 0; i < M; i++) st.insert({h[i], w[i]});

    debug(rows, cols, st);
    // それぞれの最大値
    int xmax = *max_element(rows.begin(), rows.end());
    int ymax = *max_element(cols.begin(), cols.end());

    // 最大値のある行, 列の番号
    vector<int> X, Y;
    for(int i = 0; i < H; i++){
        if(rows[i] == xmax) X.emplace_back(i);
    }
    for(int i = 0; i < W; i++){
        if(cols[i] == ymax) Y.emplace_back(i);
    }

    // ここの調べる回数は高々M回
    for(auto x: X){
        for(auto y: Y){
            if(st.find({x, y}) == st.end()){
                cout << xmax + ymax << endl;
                return 0;
            }
        }
    }

    cout << xmax + ymax - 1 << endl;
}