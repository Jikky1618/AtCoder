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
    string S;
    cin >> S;
    vector<int> C(N);
    for(int i = 0; i < N; i++) cin >> C[i], C[i]--;

    vector<string> col(M, string(""));
    for(int i = 0; i < N; i++){
        col[C[i]] += S[i];
    }
    for(int i = 0; i < M; i++){
        rotate(col[i].rbegin(), col[i].rbegin() + 1, col[i].rend());
    }
    
    vector<int> pos(M);
    string ans = "";
    for(int i = 0; i < N; i++){
        ans += col[C[i]][pos[C[i]]];
        pos[C[i]]++;
    }

    cout << ans << '\n';
}