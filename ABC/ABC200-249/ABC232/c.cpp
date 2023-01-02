#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector G(N,vector<int>(N)), H(N, vector<int>(N));
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B; A--, B--;
        G[A][B] = G[B][A] = 1;
    }
    for(int i = 0; i < M; i++){
        int C, D; cin >> C >> D; C--, D--;
        H[C][D] = H[D][C] = 1;
    }

    vector<int> P(N);
    iota(P.begin(), P.end(), 0); // 0, 1, ..., N - 1
    bool is_isomorphism = false; 
    do{
        bool flag = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(G[i][j] != H[P[i]][P[j]]) flag = false;
            }
        }

        if(flag) is_isomorphism = true;
    }while(next_permutation(P.begin(), P.end()));

    cout << (is_isomorphism ? "Yes" : "No") << endl;
    return 0;
}