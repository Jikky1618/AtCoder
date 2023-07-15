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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0, sum = 0;
    for(int left = 0, right = 0; left < N; left++){
        // [left, right + 1) が K 以下なら right を進める
        while(right < N && sum + A[right] <= K) sum += A[right], right++;
        debug(left, right, sum, right - left);
        // [left, right) のとき, left とできるペア(left, leftを含む)は right - left 組
        ans += right - left;
        // left == right のとき, [left, right) はなにも含んでいない
        (left == right ? right++ : sum -= A[left]);
    }

    cout << ans << endl;
}