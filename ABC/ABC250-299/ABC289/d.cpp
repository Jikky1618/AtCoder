#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = 1e5 + 10;

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
    int M;
    cin >> M;
    vector<int> B(M);
    for(int i = 0; i < M; i++) cin >> B[i];
    int X;
    cin >> X;

    vector<int> mochi(MAX + 1);
    for(int i = 0; i < M; i++){
        mochi[B[i]] = 1;
    }

    // dp[i] := i段目に登ることができるか
    vector<int> dp(MAX + 1);
    dp[0] = 1;
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < N; j++){
            if(i + A[j] < MAX && mochi[i] == 0) dp[i + A[j]] |= dp[i];
        }
    }

    cout << (dp[X] ? "Yes" : "No") << endl;
}