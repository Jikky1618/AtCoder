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
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    // LCP(s, t) < LCP(s, u) ならば, s < t < u はあり得ない。
    // 辞書順にソートして LCP を求める
    vector<int> id(N);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int i, int j){
        return S[i] < S[j];
    });

    vector<int> ans(N);
    for(int i = 0; i < N - 1; i++){
        int lcp = 0, M = min(S[id[i]].size(), S[id[i + 1]].size());
        for(int j = 0; j < M; j++){
            if(S[id[i]][j] != S[id[i + 1]][j]) break;
            lcp++;
        }
        ans[id[i]] = max(ans[id[i]], lcp);
        ans[id[i + 1]] = max(ans[id[i + 1]], lcp);
    }

    for(int i = 0; i < N; i++) cout << ans[i] << '\n';
}