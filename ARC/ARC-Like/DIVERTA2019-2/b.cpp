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
    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];

    // corner case: N = 1
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }

    int ans = INF;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            ll p = x[j] - x[i], q = y[j] - y[i];

            int cnt = 0;
            // 始める点を全て探索
            for(int k = 0; k < N; k++){
                // 地点 k から {p, q} でいける地点をすべて探索
                for(int l = 0; l < N; l++){
                    if(k == l) continue;
                    if(p == x[l] - x[k] && q == y[l] - y[k]) cnt++;
                }
            }

            ans = min(ans, N - cnt);
        }
    }

    cout << ans << endl;
}