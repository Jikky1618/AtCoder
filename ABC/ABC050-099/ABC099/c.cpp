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

    // dp[i] := i 円引き出す為の最小手数
    vector<int> dp(N + 1, -1);
    queue<int> que;
    dp[0] = 0;
    que.emplace(0);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        // 1 円引き出す
        if(now + 1 <= N && dp[now + 1] == -1){
            dp[now + 1] = dp[now] + 1;
            que.emplace(now + 1);
        }
        // 6^n 円引き出す
        for(int nx = 6; now + nx <= N; nx *= 6){;
            if(dp[now + nx] == -1){
                dp[now + nx] = dp[now] + 1;
                que.emplace(now + nx);
            }
        }
        // 9^n 円引き出す
        for(int nx = 9; now + nx <= N; nx *= 9){
            if(dp[now + nx] == -1){
                dp[now + nx] = dp[now] + 1;
                que.emplace(now + nx);
            }
        }
    }

    cout << dp[N] << endl;
}