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
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        cin >> C[i];
        for(int j = 0; j < M; j++){
            cin >> A[i][j];
        }
    }

    int ans = INF;
    for(int bit = 0; bit < (1 << N); bit++){
        vector<int> V(M); // 理解度
        int money = 0;
        for(int i = 0; i < N; i++){
            if((bit >> i) & 1){
                money += C[i];
                for(int j = 0; j < M; j++){
                    V[j] += A[i][j];
                }
            }
        }

        bool flag = true;
        for(int i = 0; i < M; i++){
            if(V[i] < X) flag = false;
        }
        if(flag) ans = min(ans, money);
    }

    cout << (ans == INF ? -1 : ans) << endl;
}