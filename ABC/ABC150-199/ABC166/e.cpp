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

    map<ll, int> cnt;
    // i < j としたとき i + A[i] = j - A[j] が条件の組
    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += cnt[i - A[i]];
        cnt[i + A[i]]++;
    }

    cout << ans << endl;
}