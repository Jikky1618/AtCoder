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

    sort(A.begin(), A.end());

    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    debug(A, S);
    int idx = 0;
    for(int i = 1; i < N; i++){
        // 1つ大きい生き物に吸収できない場合
        // それより小さい生き物はすべて残ることはない
        if(S[i] * 2 < A[i]) idx = i;
    }

    int ans = N - idx;
    cout << ans << endl;
}