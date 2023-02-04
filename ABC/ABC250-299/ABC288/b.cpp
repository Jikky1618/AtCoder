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
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<string> T(K);
    for(int i = 0; i < K; i++) T[i] = S[i];

    sort(T.begin(), T.end());
    for(int i = 0; i < K; i++) cout << T[i] << endl;
}