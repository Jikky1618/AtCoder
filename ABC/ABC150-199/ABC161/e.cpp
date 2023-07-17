#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;

    // 左右から働く日を Greedy に求める
    vector<int> left(N), right(N);
    int last = -INF; // last := 最後に働いた日
    for(int i = 0; i < N; i++){
        // 前回働いた日から C + 1 日以上たったなら働ける
        if(S[i] == 'o' && last + C + 1 <= i){
            left[i]++;
            last = i;
        }
    }
    last = INF;
    for(int i = N - 1; i >= 0; i--){
        // 前回働いた日から C + 1 日以上たったなら働ける
        if(S[i] == 'o' && i <= last - C - 1){
            right[i]++;
            last = i;
        }
    }
    // 左右から累積和を取る
    vector<int> accl(N + 1), accr(N + 1);
    for(int i = 0; i < N; i++) accl[i + 1] = accl[i] + left[i];
    for(int i = 0; i < N; i++) accr[i + 1] = accr[i] + right[N - i - 1];
    debug(accl, accr);

    // i 日目に働かないときの働く日数の最適解が K 日未満なら i 日目は働く
    for(int i = 0; i < N; i++){
        if(S[i] == 'x') continue;
        // [0, i) + (i, N - 1]
        if(accl[i] + accr[N - i - 1] < K){
            cout << i + 1 << '\n';
        }
    }
}