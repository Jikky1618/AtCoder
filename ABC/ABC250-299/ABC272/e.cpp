#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // x回目の操作後の数列にどの数があるか(数は0以上, N以下で十分)
    vector<set<int>> st(M + 1);
    for(int i = 0; i < N; i++){
        // cnt := 何回目の操作でA[i]が0以上になるか
        int cnt = max(0, ceil(-A[i], (i + 1)));
        for(int j = cnt; j <= M; j++){
            int val = A[i] + (i + 1) * j;
            if(val > N) break;
            st[j].insert(val);
        }
    }

    // 1回目からM回目までのMexを求める
    for(int i = 1; i <= M; i++){
        for(int j = 0; j <= N; j++){
            if(!st[i].count(j)){
                cout << j << "\n";
                break;
            }
        }
    }
}