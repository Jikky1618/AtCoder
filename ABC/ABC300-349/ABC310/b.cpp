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
    vector<int> P(N), C(N);
    vector<vector<int>> F(N, vector<int>(M));
    for(int i = 0; i < N; i++){
        cin >> P[i] >> C[i];
        for(int j = 0; j < C[i]; j++){
            int f; cin >> f, f--;
            F[i][f] = true;
        }
    }

    debug(F);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(P[i] < P[j] || i == j) continue;
            // flag2 := j 番目の製品は i 番目の製品が持つ機能をすべてもつか
            // flag3 := j 番目の製品は i 番目の製品にない機能を 1 つ以上もつか
            bool flag2 = true, flag3 = false;
            for(int k = 0; k < M; k++){
                // 2つめの条件を満たさない
                if(F[i][k] == true && F[j][k] == false) flag2 = false;
                // これは3つめの条件を満たす
                if(F[i][k] == false && F[j][k] == true) flag3 = true;
            }

            if(flag2 && (P[i] > P[j] || flag3)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}