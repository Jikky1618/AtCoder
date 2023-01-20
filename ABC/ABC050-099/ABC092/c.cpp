#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N + 2);
    for(int i = 1; i < N + 1; i++) cin >> A[i];

    int sum = 0;
    // i -> i + 1 の距離
    vector<int> diff(N + 1);
    for(int i = 0; i < N + 1; i++){
        diff[i] = abs(A[i + 1] - A[i]);
        sum += diff[i];
    }

    // i -> i + 2 の距離
    vector<int> B(N);
    for(int i = 0; i < N; i++){
        B[i] = abs(A[i + 2] - A[i]);
    }

    // 差分更新
    for(int i = 0; i < N; i++){
        int ans = sum - (diff[i] + diff[i + 1]) + B[i];
        cout << ans << "\n";
    }
}