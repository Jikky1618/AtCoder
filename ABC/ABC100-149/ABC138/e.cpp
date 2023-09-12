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
    string S, T;
    cin >> S >> T;

    ll N = S.size(), M = T.size();
    map<char, vector<int>> pos;
    for(int i = 0; i < N; i++) pos[S[i]].emplace_back(i);
    for(int i = 0; i < N; i++) pos[S[i]].emplace_back(i + N);

    ll p = -1, np = 0, ans = 0;
    for(int i = 0; i < M; i++){
        // S p 文字目以降での T[i] が一番手前にある場所を二分探索
        auto itr = upper_bound(pos[T[i]].begin(), pos[T[i]].end(), p);
        // なければ、存在しない
        if(itr == pos[T[i]].end()){
            cout << -1 << endl;
            return 0;
        }
        np = *itr;
        ans += np - p;
        p = np, p %= N;
    }
    debug(pos, ans);
    cout << ans << endl;
}