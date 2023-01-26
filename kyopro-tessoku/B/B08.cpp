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
    vector V(1510, vector<int>(1510));
    for(int i = 0; i < N; i++){
        int X, Y; cin >> X >> Y;
        V[X][Y]++;
    }
    int Q;
    cin >> Q;

    // 二次元累積和
    vector S(1511, vector<int>(1511));
    for(int i = 0; i < 1510; i++){
        for(int j = 0; j < 1510; j++){
            S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + V[i][j];
        }
    }

    // クエリに答える
    while(Q--){
        int A, B, C, D; cin >> A >> B >> C >> D, C++, D++;
        cout << S[C][D] - S[A][D] - S[C][B] + S[A][B] << '\n';       
    }
}