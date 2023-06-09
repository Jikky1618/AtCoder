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
    vector<int> x(M), y(M);
    for(int i = 0; i < M; i++){
        cin >> x[i] >> y[i], x[i]--, y[i]--;
    }

    vector<int> cnt(N, 1), flag(N);
    flag[0] = true;
    for(int i = 0; i < M; i++){
        flag[y[i]] |= flag[x[i]];
        cnt[x[i]]--, cnt[y[i]]++;
        if(cnt[x[i]] == 0) flag[x[i]] = false;
    }

    int ans = 0;
    for(int i = 0; i < N; i++) if(flag[i]) ans++;

    cout << ans << endl;
}