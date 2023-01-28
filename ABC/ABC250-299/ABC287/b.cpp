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
    int N, M;
    cin >> N >> M;
    vector<string> S(N), T(M);
    for(int i = 0; i < N; i++) cin >> S[i];
    for(int i = 0; i < M; i++) cin >> T[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        bool flag = false;
        for(int j = 0; j < M; j++){
            if(S[i].substr(3) == T[j]) flag = true;
        }
        if(flag) ans++;
    }

    cout << ans << endl;
}