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
    string X;
    cin >> X;

    int N = X.size();
    vector<int> A(N);
    for(int i = 0; i < N; i++) A[i] = X[i] - '0';

    vector<int> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    for(int i = N; i >= 1; i--){
        S[i - 1] += S[i] / 10;
        S[i] %= 10;
    }

    string ans = "";
    if(S[0] != 0){
        ans = S[0] + '0';
    }
    for(int i = 1; i <= N; i++){
        ans += S[i] + '0';
    }

    cout << ans << endl;
}