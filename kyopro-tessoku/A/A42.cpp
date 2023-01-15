#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    auto get_score = [&](int a, int b) -> int {
        int res = 0;
        for(int i = 0; i < N; i++){
            if(a <= A[i] && A[i] <= a + K && b <= B[i] && B[i] <= b + K) res++;
        }
        return res;
    };

    int ans = 0;
    // 体力a, 気力bの下限を全探索
    for(int a = 0; a <= 100; a++){
        for(int b = 0; b <= 100; b++){
            int score = get_score(a, b);
            ans = max(ans, score);
        }
    }

    cout << ans << endl;
}