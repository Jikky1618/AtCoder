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
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector dist(N, vector<int>(N, INF));
    vector val(N, vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == 'Y') dist[i][j] = 1, val[i][j] = A[j];
        }
        dist[i][i] = 0, val[i][i] = 0;
    }

    // ワーシャルフロイド法
    for(int i = 0; i < N; i++){
        for(int to = 0; to < N; to++){
            for(int from = 0; from < N; from++){
                // より最短の場合
                if(dist[from][i] + dist[i][to] < dist[from][to]){
                    dist[from][to] = dist[from][i] + dist[i][to];
                    val[from][to] = val[from][i] + val[i][to];
                }
                // 同じ距離でお土産の価値の総和が高い場合
                else if((dist[from][i] + dist[i][to] == dist[from][to]) && (val[from][i] + val[i][to] > val[from][to])){
                    val[from][to] = val[from][i] + val[i][to];
                }
            }
        }
    }

    int Q;
    cin >> Q;
    while(Q--){
        int U, V; cin >> U >> V, U--, V--;
        if(dist[U][V] == INF){
            cout << "Impossible\n";
        }else{
            // A[U]のお土産も買った合計が答え！
            cout << dist[U][V] << " " << val[U][V] + A[U] << '\n';
        }
    }
}