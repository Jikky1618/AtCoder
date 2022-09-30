#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h1, w1;
    cin >> h1 >> w1;
    vector<vector<int>> a(h1,vector<int>(w1));
    for(int i = 0; i < h1; i++){
        for(int j = 0; j < w1; j++) cin >> a[i][j];
    }
    int h2,w2;
    cin >> h2 >> w2;
    vector<vector<int>> b(h2,vector<int>(w2));
    for(int i = 0; i < h2; i++){
        for(int j = 0; j < w2; j++) cin >> b[i][j];
    }

    bool can = false;
    // 行に対してBit全探索
    for(int bit_h = 0; bit_h < (1 << h1); bit_h++){
        // 列に対してBit全探索
        for(int bit_w = 0; bit_w < (1 << w1); bit_w++){
            // Aの残す行列の行: new_h, 列: new_w
            vector<int> new_h,new_w;
            for(int i = 0; i < h1; i++){
                if((bit_h >> i) & 1) new_h.push_back(i);
            }
            for(int i = 0; i < w1; i++){
                if((bit_w >> i) & 1) new_w.push_back(i);
            }
            // 配列外参照を防ぐためBとサイズが違う配列はスキップ
            if(new_h.size() != h2 || new_w.size() != w2) continue;

            // Aの残す行、列のみで作る行列: new_v
            vector<vector<int>> new_v(h2,vector<int>(w2));
            for(int i = 0; i < h2; i++){
                for(int j = 0; j < w2; j++){
                    new_v[i][j] = a[new_h[i]][new_w[j]];
                }
            }

            // 一致かどうか判定
            if(new_v == b) can = true;
        }
    }
    
    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}