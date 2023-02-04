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
    // 月1, 月2, 火1,... として処理
    vector F(N, vector<int>(10));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 10; j++){
            cin >> F[i][j];
        }
    }
    vector P(N, vector<int>(11));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 11; j++){
            cin >> P[i][j];
        }
    }

    int ans = -INF;
    // 営業する日をbit全探索
    for(int bit = 1; bit < (1 << 10); bit++){
        vector<int> c(N, 0);
        // 店を全探索
        for(int i = 0; i < N; i++){
            // 曜日を全探索
            for(int j = 0; j < 10; j++){
                if(((bit >> j) & 1) && F[i][j]) c[i]++;
            }
        }
        // 得点を計算
        int point = 0;
        for(int i = 0; i < N; i++){
            point += P[i][c[i]];
        }
        ans = max(ans, point);
    }

    cout << ans << endl;
}