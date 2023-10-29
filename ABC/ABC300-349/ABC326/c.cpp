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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    int ans = 0;
    // 各プレゼントから M 伸ばす
    for(int i = 0; i < N; i++){
        int pos = lower_bound(A.begin(), A.end(), A[i] + M) - A.begin();
        ans = max(ans, pos - i);
    }

    cout << ans << endl;
}