#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <atcoder/modint>
using namespace atcoder;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T>
vector<vector<T>> mul(vector<vector<T>> &A, vector<vector<T>> &B){
    int ha = A.size(), hb = B.size(), wb = B.front().size();
    vector<vector<T>> R(ha, vector<T>(wb, 0));
    for(int i = 0; i < ha; i++){
        for(int j = 0; j < wb; j++){
            for(int k = 0; k < hb; k++){
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return R;
}

template<class T>
vector<vector<T>> pow(vector<vector<T>> &A, uint64_t n){
    int a = A.size();
    vector<vector<T>> R(a, vector<T>(a));
    auto B = A;
    for(int i = 0; i < a; i++) R[i][i] = 1;
    while(n > 0){
        if(n & 1) R = mul(R, B);
        B = mul(B, B);
        n >>= 1;
    }
    return R;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, X, M;
    cin >> A >> X >> M;

    modint::set_mod(M);

    vector<vector<modint>> mat = {{A, 1}, {0, 1}};
    vector<vector<modint>> ans = pow(mat, X);

    cout << ans[0][1].val() << endl;
}