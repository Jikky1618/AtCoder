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
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i], A[i]--;

    // to[i] := k 本目の後, 左から i 番目にいるとき終了時到達する場所
    vector<int> to(N);
    iota(to.begin(), to.end(), 0);
    for(int i = M - 1; i >= 0; i--){
        // 後ろから逆算
        swap(to[A[i]], to[A[i] + 1]);
    }

    vector<int> B(N);
    iota(B.begin(), B.end(), 0);
    int p1 = 0; // 1 のある場所
    // 現在 to[i] := 開始後, 左から i 番目にいるとき終了時到達する場所
    // k 本目を全探索
    for(int k = 0; k < M; k++){
        // これで, to[i] := k 本目の後, 左から i 番目にいるとき終了時到達する場所に更新
        swap(to[A[k]], to[A[k] + 1]);
        debug(to);

        // k 本目を無視したときの答えを出力
        cout << to[p1] + 1 << '\n';
        // k 本目を通ったときのあみだくじを更新して, p1 も更新
        if(B[A[k]] == 0) p1++;
        if(B[A[k] + 1] == 0) p1--;
        swap(B[A[k]], B[A[k] + 1]);
    }
}