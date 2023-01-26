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
    int D;
    cin >> D;

    // 累積max
    vector<int> MaxL(N + 1), MaxR(N + 1);
    for(int i = 0; i < N; i++)  MaxL[i + 1] = max(MaxL[i], A[i]);
    for(int i = 0; i < N; i++)  MaxR[i + 1] = max(MaxR[i], A[N - i - 1]);

    // クエリに答える
    while(D--){
        int L, R; cin >> L >> R, L--, R--;
        cout << max(MaxL[L], MaxR[N - R - 1]) << '\n';
    }
}