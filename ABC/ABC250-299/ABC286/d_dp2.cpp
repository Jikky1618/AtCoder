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
    int N, X;
    cin >> N >> X;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // dp[i] := i円支払うことができるか
    vector<int> dp(X + 1);
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = X; j >= 0; j--){ // 逆順に操作
            for(int k = 0; k <= B[i]; k++){
                if(j + A[i] * k <= X) dp[j + A[i] * k] |= dp[j];
            }
        }
    }

    cout << (dp[X] ? "Yes" : "No") << endl;
}