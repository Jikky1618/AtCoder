#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(M), B(M), C(M);
    for(int i = 0; i < M; i++) cin >> A[i] >> B[i] >> C[i], A[i]--, B[i]--;

    vector<int> E(K);
    for(int i = 0; i < K; i++) cin >> E[i], E[i]--;

    vector<ll> dist(N, INF);
    dist[0] = 0;
    for(int i = 0; i < K; i++){
        int from = A[E[i]], to = B[E[i]], cost = C[E[i]];
        if(dist[to] > dist[from] + cost){
            dist[to] = dist[from] + cost;
        }
    }

    cout << (dist[N - 1] == INF ? -1 : dist[N - 1]) << endl;
}