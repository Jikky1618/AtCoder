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
    vector<int> P(N), L(M), D(M);
    for(int i = 0; i < N; i++) cin >> P[i];
    for(int i = 0; i < M; i++) cin >> L[i];
    for(int i = 0; i < M; i++) cin >> D[i];

    // 使えるクーポンは L[i] が高いほど条件が高い
    // なるべく D[i] が高い順に使っていく
    // D[i], L[i] のペアを昇順にソート
    vector<pair<int, int>> C(M);
    for(int i = 0; i < M; i++) C[i] = {D[i], L[i]};
    sort(C.begin(), C.end(), greater<pair<int, int>>());

    // 未割引商品を multiset で管理
    multiset<int> ms;
    for(int i = 0; i < N; i++) ms.insert(P[i]);

    debug(C, ms);
    // 割引済商品を discounted に追加
    vector<int> discounted;
    for(int i = 0; i < M; i++){
        // 適用する商品のイテレータ
        auto itr = ms.lower_bound(C[i].second);
        // 適用できる商品があるなら
        if(itr != ms.end()){
            int val = *itr;
            // val 円の商品を multiset から削除
            ms.erase(itr);
            // discounted に val - D[i] 円を追加
            discounted.emplace_back(val - C[i].first);
        }
    }

    debug(discounted, ms);
    ll ans = 0;
    for(auto p: ms) ans += p;
    for(auto p: discounted) ans += p;

    cout << ans << endl;
}