#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int maxmin(int a, int b, int c, int d){
    return max({a, b, c, d}) - min({a, b, c, d});
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N), D(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> D[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());

    int ans = INF, a, b, c, d, Min;
    for(int i = 0; i < N; i++){
        // A[i] を最小の身長とする
        Min = A[i];
        b = *lower_bound(B.begin(), B.end(), Min);
        c = *lower_bound(C.begin(), C.end(), Min);
        d = *lower_bound(D.begin(), D.end(), Min);
        ans = min(ans, maxmin(Min, b, c, d));

        // B[i] を最小の身長とする
        Min = B[i];
        a = *lower_bound(A.begin(), A.end(), Min);
        c = *lower_bound(C.begin(), C.end(), Min);
        d = *lower_bound(D.begin(), D.end(), Min);
        ans = min(ans, maxmin(a, Min, c, d));

        // C[i] を最小の身長とする
        Min = C[i];
        a = *lower_bound(A.begin(), A.end(), Min);
        b = *lower_bound(B.begin(), B.end(), Min);
        d = *lower_bound(D.begin(), D.end(), Min);
        ans = min(ans, maxmin(a, b, Min, d));

        // D[i] を最小の身長とする
        Min = D[i];
        a = *lower_bound(A.begin(), A.end(), Min);
        b = *lower_bound(B.begin(), B.end(), Min);
        c = *lower_bound(C.begin(), C.end(), Min);
        ans = min(ans, maxmin(a, b, c, Min));
    }

    cout << ans << endl;
    return 0;
}