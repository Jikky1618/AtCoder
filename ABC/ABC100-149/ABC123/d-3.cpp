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
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    for(int i = 0; i < X; i++) cin >> A[i];
    for(int i = 0; i < Y; i++) cin >> B[i];
    for(int i = 0; i < Z; i++) cin >> C[i];

    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    vector<ll> ans;
    for(int i = 0; i < X; i++){
        for(int j = 0; j < Y; j++){
            for(int k = 0; k < Z; k++){
                if((i + 1) * (j + 1) * (k + 1) <= K){
                    ans.emplace_back(A[i] + B[j] + C[k]);
                }else{
                    break;
                }
            }
        }
    }

    sort(ans.begin(), ans.end(), greater<ll>());
    for(int i = 0; i < K; i++){
        cout << ans[i] << "\n";
    }
}