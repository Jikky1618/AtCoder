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
    int N, C, K;
    cin >> N >> C >> K;
    vector<ll> T(N);
    for(int i = 0; i < N; i++) cin >> T[i];

    sort(T.begin(), T.end());
    T.emplace_back(2e9 + 1); // 番兵
    int ans = 0, cnt = 0, last = 0;
    for(int i = 0; i < N; i++){
        if(cnt == 0) last = T[i];
        cnt++;
        if(last + K < T[i + 1] || cnt == C) ans++, cnt = 0;
    }

    cout << ans << endl;
}