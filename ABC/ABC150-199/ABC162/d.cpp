#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#else
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;

    auto naive = [&]() -> void {
        int ans = 0;
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                for(int k = j + 1; k < N; k++){
                    if(S[i] == S[j] || S[j] == S[k] || S[k] == S[i]) continue;
                    if(j - i != k - j){
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
    };

    const string col = "RGB";
    // 各文字ごとに累積和
    vector acc(3, vector<int>(N + 1));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < N; j++){
            acc[i][j + 1] = acc[i][j] + (S[j] == col[i]);
        }
    }

    ll ans = 0;
    // j, kを全探索
    for(int j = 0; j < N; j++){
        for(int k = j + 1; k < N; k++){
            if(S[j] == S[k]) continue;
            // num := S[i]でもS[j]でない色
            int num = 0;
            for(int i = 0; i < 3; i++) if(col[i] != S[j] && col[i] != S[k]) num = i;

            // i < j を満たすiでS[i] = col[num]の数をカウント
            ll cnt = acc[num][j] - (2 * j - k < N && S[2 * j - k] == col[num]);
            ans += cnt;
        }
    }

    cout << ans << endl;
}