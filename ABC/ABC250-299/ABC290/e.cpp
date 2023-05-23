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

    vector<int> cnt(N + 1);
    for(int i = 0; i < N; i++) cnt[A[i]]++;

    ll ans = 0, val = 0, total = N;
    for(int i = 0; i < N / 2; i++){
        // 左側の要素
        int left = i;
        // 不一致数を計算
        val = total - cnt[A[left]];
        // 重みを計算
        ans += val * (i + 1);
        total--, cnt[A[left]]--;
        // 右側の要素
        int right = N - i - 1;
        // 不一致数を計算
        val = total - cnt[A[right]];
        // 重みを計算
        ans += val * (i + 1);
        total--, cnt[A[right]]--;
    }

    cout << ans << endl;
}