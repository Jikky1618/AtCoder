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
    cin >> N, N--;
    vector<int> C(N), S(N), F(N);
    for(int i = 0; i < N; i++) cin >> C[i] >> S[i] >> F[i];

    // 駅iから駅Nに到達できる時間
    for(int i = 0; i < N; i++){
        int ans = 0;
        for(int j = i; j < N; j++){
            ans = max(ans, S[j]);
            // d := 駅jでの待機時間
            int d = ans - S[j];
            if(d % F[j] != 0) d = F[j] - (d % F[j]);
            else d = 0;

            ans += d + C[j];
        }
        cout << ans << endl;
    }
    cout << 0 << endl;
}