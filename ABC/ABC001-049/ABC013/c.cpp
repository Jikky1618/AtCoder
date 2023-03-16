#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    ll N, H, A, B, C, D, E;
    cin >> N >> H >> A >> B >> C >> D >> E;

    ll ans = INF;
    for(int i = 0; i <= N; i++){
        if(H + B * i - E * (N - i) > 0){
            ans = min(ans, A * i);
        }else{
            int j = (N * E - H - (B + E) * i) / (D + E) + 1;
            if(i + j <= N) ans = min(ans, A * i + C * j);
        }
    }

    cout << ans << endl;
}