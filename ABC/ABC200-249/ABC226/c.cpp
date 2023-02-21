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
    vector<int> T(N);
    vector<vector<int>> A(N);
    for(int i = 0; i < N; i++){
        int K; cin >> T[i] >> K;
        A[i].resize(K);
        for(int j = 0; j < K; j++) cin >> A[i][j], A[i][j]--;
    }

    ll ans = 0;
    vector<bool> used(N);
    auto dfs = [&](auto&& self, int pos) -> void {
        for(auto e: A[pos]){
            if(used[e] == false) self(self, e);
        }
        ans += T[pos];
        used[pos] = true;
    };
    
    dfs(dfs, N - 1);
    cout << ans << endl;
}