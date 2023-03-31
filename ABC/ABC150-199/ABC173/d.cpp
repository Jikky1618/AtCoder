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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());

    ll ans = A[0]; // 一番大きい心地よさは1回のみ
    for(int i = 2; i < N; i++){
        // それ以降は降順に2回ずつ
        ans += A[i / 2];
    }

    cout << ans << endl;
}