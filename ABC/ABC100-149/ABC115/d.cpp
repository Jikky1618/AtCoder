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
    ll N, X;
    cin >> N >> X;

    // tot[i] := レベルiバーガーの層数, patty[i] := レベルiバーガーのパティ数
    vector<ll> tot(N + 1), patty(N + 1);
    tot[0] = patty[0] = 1;
    for(int i = 0; i < N; i++) tot[i + 1] = tot[i] * 2 + 3;
    for(int i = 0; i < N; i++) patty[i + 1] = patty[i] * 2 + 1;

    // レベル n のバーガーの下から x 枚に含まれるパティの枚数
    auto f = [&](auto &&self, int n, ll x) -> ll {
        if(n == 0){
            return 1;
        }else if(x == 1){
            return 0;
        }else if(x <= tot[n - 1] + 1){
            return self(self, n - 1, x - 1);
        }else if(x <= tot[n - 1] + 2){
            return patty[n - 1] + 1;
        }else if(x <= tot[n - 1] * 2 + 2){
            return patty[n - 1] + 1 + self(self, n - 1, x - tot[n - 1] - 2);
        }else{
            return patty[n - 1] * 2 + 1;
        }
    };

    cout << f(f, N, X) << endl;
}