#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    for(int i = 0; i < A; i++) cin >> a[i];
    for(int i = 0; i < B; i++) cin >> b[i];
    vector<int> x(M), y(M), c(M);
    for(int i = 0; i < M; i++){
        cin >> x[i] >> y[i] >> c[i];
    }

    int ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
    for(int i = 0; i < M; i++){
        ans = min(ans, a[x[i] - 1] + b[y[i] - 1] - c[i]);
    }

    cout << ans << endl;
    return 0;
}