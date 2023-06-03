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
    int N, K, S;
    cin >> N >> K >> S;

    vector<int> ans;
    for(int i = 0; i < K; i++) ans.emplace_back(S);
    
    int INF = (S == 1e9 ? 1 : 1e9);
    for(int i = 0; i < (N - K); i++){
        ans.emplace_back(INF);
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N - 1];
    }
}