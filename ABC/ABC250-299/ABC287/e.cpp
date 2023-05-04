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

    vector<pair<string, int>> P(N);
    for(int i = 0; i < N; i++) P[i] = {S[i], i};
    sort(P.begin(), P.end());

    vector<int> ans(N);
    for(int i = 0; i < N - 1; i++){
        int lcp = 0;
        int m = min(P[i].first.size(), P[i + 1].first.size());
        for(int j = 0; j < m; j++){
            if(P[i].first[j] != P[i + 1].first[j]) break;
            lcp++;
        }
        ans[P[i].second] = max(ans[P[i].second], lcp);
        ans[P[i + 1].second] = max(ans[P[i + 1].second], lcp);
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << '\n';
    }
}