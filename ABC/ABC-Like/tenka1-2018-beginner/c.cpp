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

    sort(A.begin(), A.end());

    ll ans = 0;
    if(N % 2 == 0){
        // 両端の要素を決定
        ll m1 = A[N / 2 - 1], m2 = A[N / 2];
        ll sum = 0;
        // 中央値に最も近い値をm1として、各要素の差分を計算
        for(int i = 0; i < N; i++) sum += abs(A[i] - m1);

        // 両端のみ1回カウント、それ以外は2回カウント
        ans = 2 * sum - abs(m2 - m1);
    }else{
        // 両端の要素の候補を決定
        ll m1 = A[N / 2 - 1], m2 = A[N / 2], m3 = A[N / 2 + 1];
        ll sum = 0;
        // 中央値に最も近い値をm2として、各要素の差分を計算
        for(int i = 0; i < N; i++) sum += abs(A[i] - m2);

        // 両端のみ1回カウント、それ以外は2回カウント(両端が{m1, m2}, {m2, m3}の2通りを考慮)
        ans = 2 * sum - min(abs(m1 - m2), abs(m3 - m2));
    }

    cout << ans << endl;
}