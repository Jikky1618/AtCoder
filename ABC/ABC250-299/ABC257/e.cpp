#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> C(9);
    for (int i = 0; i < 9; i++) cin >> C[i];

    // まず, 桁数の最大値 M を求める
    int min_cost = *min_element(C.begin(), C.end());
    int M = N / min_cost;

    // 各桁を全探索 O(N)
    string ans = "";
    for(int i = 0; i < M; i++){
        // 大きい数から検討する
        for(int j = 9; j > 0; j--){
            // i 桁目に j を用いても, M 桁になる構築方法がある場合は採用
            if(N - C[j - 1] - min_cost * (M - i - 1) >= 0){
                ans += char(j + '0');
                N -= C[j - 1];
            }
        }
    }

    cout << ans << endl;
}