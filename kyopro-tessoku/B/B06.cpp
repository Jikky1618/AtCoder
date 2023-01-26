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
    int Q;
    cin >> Q;

    // 累積和 S1: アタリの累積和、S2: ハズレの累積和
    vector<int> S1(N + 1), S2(N + 1);
    for(int i = 0; i < N; i++) S1[i + 1] = S1[i] + (A[i] == 1 ? 1 : 0);
    for(int i = 0; i < N; i++) S2[i + 1] = S2[i] + (A[i] == 0 ? 1 : 0);

    // クエリに答える
    while(Q--){
        int L, R; cin >> L >> R, L--;
        int val1 = S1[R] - S1[L], val2 = S2[R] - S2[L];
        if(val1 > val2) cout << "win" << '\n';
        if(val1 < val2) cout << "lose" << '\n';
        if(val1 == val2) cout << "draw" << '\n';
    }
}