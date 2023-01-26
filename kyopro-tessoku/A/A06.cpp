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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 累積和
    vector<int> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    // クエリに答える
    while(Q--){
        int L, R; cin >> L >> R, L--;
        cout << S[R] - S[L] << '\n'; 
    }
}