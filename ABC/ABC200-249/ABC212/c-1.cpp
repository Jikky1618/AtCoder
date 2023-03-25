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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ans = INF;
    for(int i = 0; i < N; i++){
        auto itr1 = lower_bound(B.begin(), B.end(), A[i]);
        auto itr2 = (itr1 == B.begin() ? B.begin() : prev(itr1));

        ans = min({ans, abs(A[i] - *itr1), abs(A[i] - *itr2)});
    }

    cout << ans << endl;
}