#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N, vector<ll>(N, -INF));
    for(int i = 0; i < M; i++){
        int A, B, C; cin >> A >> B >> C, A--, B--;
        G[A][B] = G[B][A] = C;
    }
    for(int i = 0; i < N; i++) G[i][i] = 0;

    debug(G);
    ll ans = 0;
    vector<int> P(N);
    iota(P.begin(), P.end(), 0);
    do{
        ll d = 0;
        for(int i = 0; i < N - 1; i++){
            if(G[P[i]][P[i + 1]] == -INF){
                d = -INF;
                break;
            }
            d += G[P[i]][P[i + 1]];
            ans = max(ans, d);
        }
        ans = max(ans, d);
    }while(next_permutation(P.begin(), P.end()));

    cout << ans << endl;
}