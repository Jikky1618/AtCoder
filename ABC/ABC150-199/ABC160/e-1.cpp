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
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<int> p(A), q(B), r(C);
    for(int i = 0; i < A; i++) cin >> p[i];
    for(int i = 0; i < B; i++) cin >> q[i];
    for(int i = 0; i < C; i++) cin >> r[i];

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());

    multiset<int> P, Q;
    for(int i = 0; i < X; i++) P.insert(p[i]);
    for(int i = 0; i < Y; i++) Q.insert(q[i]);

    for(int i = 0; i < C; i++){
        if(*P.begin() < *Q.begin()){
            if(*P.begin() < r[i]){
                P.erase(P.begin());
                P.insert(r[i]);
            }
        }else{
            if(*Q.begin() < r[i]){
                Q.erase(Q.begin());
                Q.insert(r[i]);
            }
        }
    }

    ll ans = 0;
    for(auto e: P) ans += e;
    for(auto e: Q) ans += e;

    cout << ans << endl;
}