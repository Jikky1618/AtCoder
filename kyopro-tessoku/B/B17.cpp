#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    vector<int> h(N);
    for(int i = 0; i < N; i++) cin >> h[i];

    // dp[i] := 足場iにたどり着くまでに支払うコスト
    vector<int> dp(N, INF);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        if(i + 1 < N) dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1])); 
        if(i + 2 < N) dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2])); 
    }
    debug(dp);

    vector<int> ans;
    int pos = N - 1;
    while(1){
        ans.push_back(pos + 1);
        if(pos == 0) break;

        if(dp[pos - 1] + abs(h[pos] - h[pos - 1]) == dp[pos]) pos--;
        else pos -= 2;
    }

    reverse(ans.begin(), ans.end());
    int K = ans.size();
    cout << K << endl;
    for(int i = 0; i < K; i++){
        cout << ans[i] << " \n"[i == K - 1];
    }
}