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
    vector<vector<int>> A(M);
    for(int i = 0; i < M; i++){
        int C; cin >> C;
        A[i].resize(C);
        for(int j = 0; j < C; j++) cin >> A[i][j];
    }

    int ans = 0;
    for(int bit = 0; bit < (1 << M); bit++){
        set<int> st;
        for(int i = 0; i < M; i++){
            if(!((bit >> i) & 1)) continue;
            for(int j = 0; j < (int)A[i].size(); j++){
                st.insert(A[i][j]);
            }
        }
        if(st.size() == N) ans++;
    }

    cout << ans << endl;
}