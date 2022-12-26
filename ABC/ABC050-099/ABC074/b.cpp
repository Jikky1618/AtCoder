#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    for(int i = 0; i < N; i++) cin >> x[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        int diff = min(abs(K - x[i]), x[i]);
        ans += diff * 2;
    }

    cout << ans << endl;
    return 0;
}