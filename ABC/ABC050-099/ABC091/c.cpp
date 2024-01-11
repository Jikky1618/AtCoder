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
    int N;
    cin >> N;
    vector<pair<int, int>> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i].first >> A[i].second;
    for(int i = 0; i < N; i++) cin >> B[i].first >> B[i].second;

    // 平面走査
    vector<tuple<int, int, int>> P;
    for(int i = 0; i < N; i++) P.emplace_back(A[i].first, A[i].second, 0);
    for(int i = 0; i < N; i++) P.emplace_back(B[i].first, B[i].second, 1);
    // x 座標でソート
    sort(P.begin(), P.end());

    int ans = 0;
    // 残っている赤い点の y 座標を管理
    set<int> remain;
    // 平面走査
    for(int i = 0; i < N * 2; i++){
        auto [x, y, t] = P[i];
        // 赤い点なら残りに追加する
        if(t == 0){
            remain.insert(y);
        }
        // 青い点なら残りから y 未満で最大の赤い点とペアにする
        if(t == 1){
            if(remain.empty()) continue;
            auto itr = remain.lower_bound(y);
            if(itr == remain.begin()) continue;
            remain.erase(prev(itr)), ans++;
        }
    }

    cout << ans << '\n';
}