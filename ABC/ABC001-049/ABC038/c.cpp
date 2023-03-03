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

    ll ans = 0;
    for(int left = 0, right = 0; left < N; left++){
        if(right < left) right = left;
        while(right < N - 1 && A[right] < A[right + 1]) right++;
        ans += right - left + 1;
    }

    cout << ans << '\n';
}