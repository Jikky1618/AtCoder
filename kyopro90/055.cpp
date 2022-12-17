#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, P, Q;
    cin >> N >> P >> Q;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int ans = 0;
    for(int a = 0; a < N; a++){
        for(int b = a + 1; b < N; b++){
            for(int c = b + 1; c < N; c++){
                for(int d = c + 1; d < N; d++){
                    for(int e = d + 1; e < N; e++){
                        ll val = A[a] * A[b] % P * A[c] % P * A[d] % P * A[e] % P;
                        if(val % P == Q) ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}