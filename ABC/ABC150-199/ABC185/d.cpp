#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T>
T ceil(T x, T y){
    return (x ? (x + y - 1) / y : x / y);
}

template<class T>
T floor(T x, T y){
    return (x ? x / y : (x + y - 1) / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(M);
    for(int i = 0; i < M; i++) cin >> A[i];

    A.push_back(0), A.push_back(N + 1); // 番兵

    sort(A.begin(), A.end());

    int k = INF;
    vector<int> V;
    for(int i = 0; i < M + 1; i++){
        int val = A[i + 1] - A[i] - 1;
        if(val > 0) k = min(k, val), V.push_back(val);
    }

    int ans = 0;
    for(auto&& v: V) ans += ceil(v, k);
    cout << ans << endl;
}