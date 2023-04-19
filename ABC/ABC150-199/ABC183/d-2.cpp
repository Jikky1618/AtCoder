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
    int N, W;
    cin >> N >> W;
    vector<int> S(N), T(N), P(N);
    for(int i = 0; i < N; i++) cin >> S[i] >> T[i] >> P[i];

    // イベントソート
    vector<pair<int, int>> event;
    for(int i = 0; i < N; i++){
        event.emplace_back(S[i], P[i]);
        event.emplace_back(T[i], -P[i]);
    }

    sort(event.begin(), event.end());

    ll val = 0, time = 0;
    bool flag = true;
    for(auto [t, p]: event){
        if(time < t){
            debug(val);
            if(W < val){
                flag = false;
            }
        }
        val += p;
    }

    cout << (flag ? "Yes" : "No") << endl;
}