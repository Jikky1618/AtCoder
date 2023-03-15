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
    vector<int> ng(3);
    for(int i = 0; i < 3; i++) cin >> ng[i];

    bool flag = false;
    for(int i = 0; i < 3; i++) if(ng[i] == N) flag = true;
    if(flag){
        cout << "NO" << endl;
        return 0;
    }

    // dp[i] := 値をiにできるか
    vector<int> dp(N + 1);
    dp[N] = 1;

    for(int time = 0; time < 100; time++){
        for(int i = 0; i <= N; i++){
            for(int j = 1; j <= 3; j++){
                if(i - j < 0) break;

                flag = true;
                for(int k = 0; k < 3; k++) if(ng[k] == i - j) flag = false;
                if(flag) dp[i - j] |= dp[i];
            }
        }
    }
    debug(dp);

    cout << (dp[0] ? "YES" : "NO") << endl;
}