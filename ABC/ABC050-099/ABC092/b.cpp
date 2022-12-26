#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, D, X;
    cin >> N >> D >> X;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += (1 + (D - 1) / A[i]);
    }

    cout << ans + X << endl;
    return 0;
}