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
    vector<pair<int, int>> P(M);
    for(int i = 0; i < M; i++) cin >> P[i].first >> P[i].second;

    // コストが小さい順にソート
    sort(P.begin(), P.end(), [](auto& l, auto& r){
        if(l.second != r.second){
            return l.second < r.second;
        }else{
            return l.first < r.first;
        }
    });
    debug(P);

    // N 個の頂点を 1 つのグループにする
    ll ans = 0, G = N;
    for(int i = 0; i < M; i++){
        if(G == 1) break;
        auto [A, C] = P[i];
        // G - gcd(A, G) 回で GCD(G, A) グループになる
        ans += C * (G - gcd(G, A));
        G = gcd(G, A);
    }

    debug(G);
    cout << (G == 1 ? ans : -1) << endl;
}