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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int Q;
    cin >> Q;

    vector<vector<int>> cnt(N + 1);
    for(int i = 0; i < N; i++){
        cnt[A[i]].push_back(i);
    }

    while(Q--){
        int L, R, X; cin >> L >> R >> X, L--, R--;
        int posL = lower_bound(cnt[X].begin(), cnt[X].end(), L) - cnt[X].begin();
        int posR = upper_bound(cnt[X].begin(), cnt[X].end(), R) - cnt[X].begin();
        cout << posR - posL << '\n';
    }
}