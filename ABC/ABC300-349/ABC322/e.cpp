#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    int N, K, P;
    cin >> N >> K >> P;
    vector<ll> C(N);
    vector A(N, vector<int>(K));
    for(int i = 0; i < N; i++){
        cin >> C[i];
        for(int j = 0; j < K; j++) cin >> A[i][j];
    }

    // dp[j] := i 個目までの開発案を見て, K 個のパラメータが配列 j のとき, コストの最小値
    map<vector<int>, ll> dp;
    vector<int> init(K, 0);
    dp[init] = 0;
    for(int i = 0; i < N; i++){
        map<vector<int>, ll> nx(dp);
        for(auto [key, val]: dp){
            // 開発案を採用する
            vector<int> nkey = key;
            // 各パラメータの上限は P とする
            for(int j = 0; j < K; j++) nkey[j] = min(nkey[j] + A[i][j], P);
            if(nx.count(nkey)) nx[nkey] = min(nx[nkey], val + C[i]);
            else nx[nkey] = val + C[i];
        }
        swap(dp, nx);
    }
    debug(dp);

    vector<int> goal(K, P);
    cout << (dp.count(goal) ? dp[goal] : -1) << endl;
}