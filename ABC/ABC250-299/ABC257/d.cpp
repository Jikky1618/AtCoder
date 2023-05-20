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
    vector<ll> X(N), Y(N), P(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> P[i];

    vector dist(N, vector<ll>(N));
    for(int i = 0;i < N; i++){
        for(int j = 0; j < N; j++){
            dist[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);
        }
    }

    auto check = [&](ll mid) -> bool {
        // スタート位置を全探索
        for(int i = 0; i < N; i++){
            vector<int> seen(N);
            queue<int> que;
            seen[i] = 1;
            que.emplace(i);
            
            while(!que.empty()){
                int pos = que.front(); que.pop();
                for(int j = 0; j < N; j++){
                    if(seen[j]) continue;
                    if(P[pos] * mid >= dist[pos][j]){
                        seen[j] = true;
                        que.emplace(j);
                    }
                }
            }

            bool flag = true;
            for(int j = 0; j < N; j++) if(!seen[j]) flag = false;

            if(flag) return true;
        }
        return false;
    };

    ll ok = 4e9 + 1, ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}