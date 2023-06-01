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
    int N;
    cin >> N;
    vector<double> X(N);
    vector<string> U(N);
    for(int i = 0; i < N; i++){
        cin >> X[i] >> U[i];
    }

    double ans = 0;
    for(int i = 0; i < N; i++){
        if(U[i] == "BTC"){
            ans += X[i] * 380000;
        }else{
            ans += X[i];
        }
    }

    cout << ans << endl;
}