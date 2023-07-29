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
    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    auto check = [&](int mid) -> bool {
        int cnt_A = upper_bound(A.begin(), A.end(), mid) - A.begin();
        int cnt_B = B.end() - lower_bound(B.begin(), B.end(), mid);
        debug(cnt_A, cnt_B, mid);
        return cnt_A >= cnt_B;
    };

    // 売り手の人数が買い手の人数以上になる最小の金額を二分探索
    int ok = 1e9 + 1, ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    debug(ok, ng);
    cout << ok << endl;
}