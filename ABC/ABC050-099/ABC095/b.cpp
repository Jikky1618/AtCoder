#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, X;
    cin >> N >> X;
    vector<int> m(N);
    for(int i = 0; i < N; i++) cin >> m[i];

    int sum = 0;
    for(int i = 0; i < N; i++) sum += m[i];

    int ans = N + (X - sum) / *min_element(m.begin(), m.end());

    cout << ans << endl;
    return 0;
}