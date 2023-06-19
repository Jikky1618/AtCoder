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
    vector<string> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 文字桁数で分ける
    vector<vector<string>> V(8);
    for(int i = 0; i < N; i++){
        int M = A[i].size();
        V[M].emplace_back(A[i]);
    }

    debug(V);
    vector<string> S;
    int cnt = 0;
    for(int i = 7; i >= 0; i--){
        if(V[i].empty()) continue;
        sort(V[i].begin(), V[i].end(), greater<string>());
        for(auto T: V[i]){
            if(cnt == 3) break;
            cnt++;
            S.emplace_back(T);
        }
        if(cnt == 3) break;
    }

    ll ans = 0;
    vector<int> P{0, 1, 2};
    do{
        string val = S[P[0]] + S[P[1]] + S[P[2]];
        ans = max(ans, stoll(val));
    }while(next_permutation(P.begin(), P.end()));
    
    cout << ans << endl;
}