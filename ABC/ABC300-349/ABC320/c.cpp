#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    int M;
    cin >> M;
    vector<string> S(3);
    for(int i = 0; i < 3; i++) cin >> S[i];

    int ans = INF;
    // 各 S の rotate を全探索
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            for(int k = 0; k < M; k++){
                char A = S[0][i % M];
                char B = S[1][j % M];
                char C = S[2][k % M];
                if(A == B && B == C) {
                    set<int> st = {i, j, k};
                    if(st.size() == 3){
                        ans = min(ans, max({i, j, k}));
                    }
                    if(st.size() == 2){
                        if(i == j){
                            ans = min(ans, max(i + M, k));
                        }
                        if(i == k){
                            ans = min(ans, max(i + M, j));
                        }
                        if(j == k){
                            ans = min(ans, max(j + M, i));
                        }
                    }
                    if(st.size() == 1){
                        ans = min(ans, k + M + M);
                    }
                }
            }
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}