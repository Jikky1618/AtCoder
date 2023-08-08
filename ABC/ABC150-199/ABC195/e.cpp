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
    string S, X;
    cin >> N >> S >> X;

    // i ラウンド目で高橋くんが勝つ数字の集合
    vector<set<int>> dp(N + 1);
    dp[N].insert(0);

    for(int i = N; i > 0; i--){
        for(int j = 0; j < 7; j++){
            // 高橋くんのターンの場合
            if(X[i - 1] == 'T'){
                if(dp[i].count((10 * j) % 7) || dp[i].count((10 * j + (S[i - 1] - '0')) % 7)){
                    dp[i - 1].insert(j);
                }
            }
            if(X[i - 1] == 'A'){
                if(dp[i].count((10 * j) % 7) && dp[i].count((10 * j + (S[i - 1] - '0')) % 7)){
                    dp[i - 1].insert(j);
                }
            }
        }
    }

    cout << (dp[0].count(0) ? "Takahashi" : "Aoki") << endl;
}