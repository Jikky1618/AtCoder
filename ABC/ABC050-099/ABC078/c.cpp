#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;

    // 1回あたりの実行時間
    int t = 1900 * M + 100 * (N - M);

    // 試行回数の期待値 = 確率の逆数 
    int p = 1;
    for(int i = 0; i < M; i++) p *= 2;

    int ans = t * p;
    cout << ans << endl;
}