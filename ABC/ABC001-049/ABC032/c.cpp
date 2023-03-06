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
    vector<ll> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    // 0がある場合
    if(count(S.begin(), S.end(), 0)){
        cout << S.size() << endl;
        return 0;
    }

    int ans = 0;
    ll Sum = 1;
    for(int left = 0, right = 0; left < N; left++){
        while(right < N && Sum * S[right] <= K) Sum *= S[right], right++;
        ans = max(ans, right - left);
        if(left == right) right++;
        else Sum /= S[left];
    }

    cout << ans << endl;
}