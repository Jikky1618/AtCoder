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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = -INF;
    // 高橋君の丸の付け方を全探索
    for(int i = 0; i < N; i++){
        // 青木君の丸の付け方を全探索
        int AM = -INF, TM = -INF;
        for(int j = N - 1; j >= 0; j--){
            if(i == j) continue;

            vector<int> T;
            for(int k = min(i, j); k <= max(i, j); k++) T.push_back(A[k]);

            int Aoki = 0, Takahashi = 0;
            for(int k = 0; k < (int)T.size(); k++){
                if(k % 2 == 0) Takahashi += T[k];
                else Aoki += T[k];
            }

            if(AM <= Aoki){
                AM = Aoki;
                TM = Takahashi;
            }
        }
        ans = max(ans, TM);
    }

    cout << ans << endl;
}