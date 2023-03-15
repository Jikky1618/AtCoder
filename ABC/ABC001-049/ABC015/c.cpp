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
    int N, K;
    cin >> N >> K;
    vector T(N, vector<int>(K));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++) cin >> T[i][j];
    }

    bool flag = false;
    auto dfs = [&](auto &&self, int pos = 0, int val = 0) -> void {
        if(pos == N){
            if(val == 0) flag = true;
            return;
        }
        for(int i = 0; i < K; i++){
            self(self, pos + 1, val ^ T[pos][i]);
        }
    };

    dfs(dfs);
    cout << (flag ? "Found" : "Nothing") << endl;
}