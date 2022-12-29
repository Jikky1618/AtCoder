#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> l(N);
    for(int i = 0; i < N; i++) cin >> l[i];

    sort(l.begin(), l.end(), greater<int>());
    int ans = 0;
    for(int i = 0; i < K; i++) ans += l[i];

    cout << ans << endl;
    return 0;
}