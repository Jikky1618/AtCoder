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
    vector<int> A(N), B(N), C(M), D(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < M; i++) cin >> C[i];
    for(int i = 0; i < M; i++) cin >> D[i];

    // 平面走査(x, y, t:= 0 ならチョコ, 1 なら箱)
    vector<tuple<int, int, int>> P;
    for(int i = 0; i < N; i++) P.emplace_back(A[i], B[i], 0);
    for(int i = 0; i < M; i++) P.emplace_back(C[i], D[i], 1);
    // 縦の長さでソート
    sort(P.begin(), P.end());

    // 今まで見た残っているチョコの y 座標
    multiset<int> remain;
    for(int i = 0; i < N + M; i++){
        auto [x, y, t] = P[i];
        if(t == 0){
            // 残りに追加
            remain.insert(y);
        }
        if(t == 1){
            if(remain.empty()) continue;
            // 残りから y 以下で最大のものを削除
            auto itr = remain.upper_bound(y);
            if(itr == remain.begin()) continue;
            remain.erase(prev(itr));
        }
    }
    debug(remain);
    cout << (remain.empty() ? "Yes" : "No") << '\n';
}