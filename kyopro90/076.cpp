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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 累積和
    vector<ll> S(2 * N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];
    for(int i = 0; i < N; i++) S[N + i + 1] = S[N + i] + A[i];

    auto val = [&](int l, int r) -> ll {
        return S[r] - S[l];
    };

    ll sum = val(0, N);
    // 区間をしゃくとり法
    int r = 0;
    for(int l = 0; l < N; l++){
        r = max(r, l + 1);
        while(r < 2 * N && val(l, r) < sum / 10) r++;
        if(val(l, r) ==  sum / 10){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}