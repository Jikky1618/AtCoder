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
    ll N, X;
    cin >> N >> X;
    vector<vector<ll>> A(N);
    for(int i = 0; i < N; i++){
        int L; cin >> L;
        for(int j = 0; j < L; j++){
            int a; cin >> a;
            A[i].push_back(a);
        }
    }

    int ans = 0;
    auto dfs = [&](auto &&self, int pos, ll val) -> void {
        if(pos == N){
            if(val == X) ans++;
            return;
        }
        for(auto e: A[pos]){
            if(val * e <= X) self(self, pos + 1, val * e);
        }
    };

    dfs(dfs, 0, 1);
    cout << ans << endl;
}