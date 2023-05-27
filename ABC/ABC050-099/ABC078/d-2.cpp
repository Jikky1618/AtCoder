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
    int N, Z, W;
    cin >> N >> Z >> W;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    // 山札が1枚のときは問答無用で終わり
    if(N == 1){
        ans = abs(W - A[N - 1]);
    // 2枚以上のとき, 最善は先手が全部取るか, 1枚残して全部取るか
    }else{
        ans = max(abs(W - A[N - 1]), abs(A[N - 2] - A[N - 1]));
    }

    cout << ans << endl;
}