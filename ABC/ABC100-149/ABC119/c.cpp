#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int n,a,b,c;
vector<int> l;
//構築する3本: A,B,C
int dfs(int cnt, int A, int B, int C){
    // 全ての竹を探索できたら
    if(cnt == n){
        if(min({A, B, C}) == 0) return INF; // 3本が決定していない
        return abs(A - a) + abs(B - b) + abs(C - c); // 目的の長さの差分が必要
    }

    // l[cnt] の竹を合成魔法に使わない場合
    int res = dfs(cnt + 1, A, B, C);
    // l[cnt] の竹を合成魔法に使う場合
    /*
        (X ? 10 : 0) の意味
        Xが0(まだ合成していない)なら追加MPは0, 0ではないなら(合成する)追加MPは10になる
    */ 
    // Aを合成
    res = min(res, dfs(cnt + 1, A + l[cnt], B, C) + (A ? 10 : 0));
    // Bを合成
    res = min(res, dfs(cnt + 1, A, B + l[cnt], C) + (B ? 10 : 0));
    // Cを合成
    res = min(res, dfs(cnt + 1, A, B, C + l[cnt]) + (C ? 10 : 0));

    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> n >> a >> b >> c;
    l.resize(n);
    for(int i = 0; i < n; i++) cin >> l[i];
    
    cout << dfs(0,0,0,0) << endl;
    return 0;
}