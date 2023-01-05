#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    // ソート
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    // 貪欲法
    ll ans = 0;
    for(int i = 0; i < N; i++) ans += abs(A[i] - B[i]);

    cout << ans << endl;
    return 0;
}