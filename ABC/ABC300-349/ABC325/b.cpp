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
    vector<int> W(N), X(N);
    for(int i = 0; i < N; i++) cin >> W[i] >> X[i];

    // 標準時 i 時のときに参加できる人数
    int ans = 0;
    for(int i = 0; i < 24; i++){
        int sum = 0;
        for(int j = 0; j < N; j++){
            if(9 <= (i + X[j]) % 24 && (i + X[j]) % 24 < 18) sum += W[j];
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;
}