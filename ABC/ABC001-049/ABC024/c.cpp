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
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> L(D), R(D), S(K), T(K);
    for(int i = 0; i < D; i++){
        cin >> L[i] >> R[i];
    }
    for(int i = 0; i < K; i++){
        cin >> S[i] >> T[i];
    }

    for(int i = 0; i < K; i++){
        int s = S[i], t = T[i];
        int ans = 1;
        for(int j = 0; j < D; j++, ans++){
            if(L[j] <= s && s <= R[j]){
                if(s <= t){
                    s = R[j];
                    if(s >= t) break;
                }else{
                    s = L[j];
                    if(s <= t) break;
                }
            }
        }
        cout << ans << '\n';
    }
}