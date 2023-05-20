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
    ll N, M, D;
    cin >> N >> M >> D;
    vector<ll> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());

    int pos1 = 0, pos2 = 0;
    ll ans = -1;
    for(int i = 0; i < N + M; i++){
        if(abs(A[pos1] - B[pos2]) <= D){
            ans = max(ans, A[pos1] + B[pos2]);
            break;
        }

        if(A[pos1] > B[pos2]){
            pos1++;
        }else{
            pos2++;
        }
    }

    cout << ans << endl;
}