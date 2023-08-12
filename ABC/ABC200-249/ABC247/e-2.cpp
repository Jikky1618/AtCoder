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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // all := 全ての列
    // x := x を含まない列
    // y := y を含まない列
    // xy := x, y　両方含まない列
    vector<int> all(N), x(N), y(N), xy(N);
    for(int i = 0; i < N; i++){
        // X より大きい or Y より小さい A の要素で区切る
        if(A[i] < Y || X < A[i]){
            all[i] = 1, x[i] = 1, y[i] = 1, xy[i] = 1;
        }
        // X を含む場合, x, xy を 1 にする
        if(A[i] == X){
            x[i] = 1, xy[i] = 1;
        }
        // Y を含む場合, y, xy を 1 にする
        if(A[i] == Y){
            y[i] = 1, xy[i] = 1;
        }
    }

    auto f = [&](vector<int> V) -> ll {
        ll res = 0, cnt = 0;
        for(int i = 0; i <= N; i++){
            // そこまでの連続部分列の長さを cnt としたとき
            // 連続部分列の組合せは N+1C2 通り
            if(i == N || V[i] == 1){
                res += (cnt + 1) * cnt / 2;
                cnt = 0;
            }else{
                cnt++;
            }
        }
        return res;
    };

    // 包除原理
    ll ans = f(all) - f(x) - f(y) + f(xy);
    cout << ans << endl;
}