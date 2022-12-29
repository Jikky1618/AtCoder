#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, S, T, W;
    cin >> N >> S >> T >> W;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(S <= W && W <= T) ans++;
        W += A[i];
    }

    cout << ans << endl;
    return 0;
}