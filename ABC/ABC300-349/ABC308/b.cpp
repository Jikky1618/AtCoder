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
    vector<string> C(N), D(M);
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < M; i++) cin >> D[i];
    vector<int> P(M + 1);
    for(int i = 0; i < M + 1; i++) cin >> P[i];

    map<string, int> mp;
    for(int i = 0; i < M; i++){
        mp[D[i]] = P[i + 1];
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(mp.count(C[i])){
            ans += mp[C[i]];
        }else{
            ans += P[0];
        }
    }

    cout << ans << endl;
    
}