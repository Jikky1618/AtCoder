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
    int N, K, Q;
    cin >> N >> K >> Q;

    ll ans = 0;
    multiset<ll> L, R;
    vector<ll> A(N, 0);

    auto push = [&](ll x) -> void {
        // とりあえず x を left に挿入する
        ans += x;
        L.insert(x);

        // left のサイズが K を超えるなら left の最小値を right に移す
        if((int)L.size() > K){
            ll val = *L.begin();
            ans -= val;
            R.insert(val);
            L.erase(L.find(val));
        }
    };

    auto pop = [&](ll x) -> void {
        // とりあえず x を削除する
        if(L.find(x) != L.end()){
            L.erase(L.find(x));
            ans -= x;
        }else if(R.find(x) != R.end()){
            R.erase(R.find(x));
        }

        // left のサイズが K 未満になるなら right の最大値を left に移す
        if((int)L.size() < K){
            ll val = *R.rbegin();
            ans += val;
            L.insert(val);
            R.erase(R.find(val));
        }
    };

    for(int i = 0; i < 2 * N; i++) push(0);
    while(Q--){
        ll X, Y; cin >> X >> Y, X--;
        pop(A[X]);
        A[X] = Y;
        push(A[X]);
        cout << ans << "\n";
    }
}