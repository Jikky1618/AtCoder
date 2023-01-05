#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int Q;
    cin >> Q;

    sort(A.begin(), A.end()); // 予めソート
    while(Q--){
        int B; cin >> B;

        // 二分探索
        int pos = lower_bound(A.begin(), A.end(), B) - A.begin();

        // posの前後の要素の最小を求める
        int diff1 = INF, diff2 = INF;
        if(pos < N) diff1 = abs(B - A[pos]);
        if(pos > 0) diff2 = abs(B - A[pos - 1]);

        // 出力
        cout << min(diff1, diff2) << '\n';
    }
    return 0;
}