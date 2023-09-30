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
    vector<ll> T(M), W(M), S(M);
    for(int i = 0; i < M; i++) cin >> T[i] >> W[i] >> S[i];

    // イベントソート
    vector<tuple<ll, ll, ll>> events;
    for(int i = 0; i < M; i++) {
        // second = 0 のとき, i 回目のそうめんクエリで得た人が列に戻るクエリ
        events.emplace_back(T[i] + S[i], 0, i);
        // second = 1 のとき, そうめんが流れるクエリ
        events.emplace_back(T[i], 1, i);
    }
    sort(events.begin(), events.end());

    set<ll> st; // 列にいる人の集合
    for(int i = 0; i < N; i++) st.insert(i); // 最初は全員いる
    vector<ll> ans(N), eat(M, -1); // eat[i] := i 番目のそうめんクエリで得た人
    for(int i = 0; i < 2 * M; i++){
        auto [time, type, idx] = events[i];
        if(type == 0) {
            if(eat[idx] != -1) st.insert(eat[idx]);
            eat[idx] = -1;
        }
        if(type == 1) {
            if(st.empty()) continue; // 誰も並んでいなければ飛ばす
            int pos = *st.begin();
            st.erase(st.begin());
            ans[pos] += W[idx];
            eat[idx] = pos;
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << '\n';
    }
}