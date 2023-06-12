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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // ref. https://qiita.com/GeekMasahiro/items/08f8094057ad81d90a2f
    // A[i] までの睡眠時間の合計
    vector<int> S(N);
    for(int i = 1; i < N; i++){
        if(i % 2 == 0){
            S[i] = S[i - 1] + (A[i] - A[i - 1]);
        }else{
            S[i] = S[i - 1];
        }
    }

    debug(S);
    auto f = [&](int t) -> int {
        int p = upper_bound(A.begin(), A.end(), t) - A.begin() - 1;
        // 時間 t が睡眠時間の区間かどうかで場合分け
        if(p % 2 == 0){
            return S[p];
        }else{
            return S[p] + t - A[p];
        }
    };

    int Q;
    cin >> Q;
    while(Q--){
        int l, r; cin >> l >> r;
        cout << f(r) - f(l) << '\n';
    }
}