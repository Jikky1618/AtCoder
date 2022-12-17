#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> C(N), P(N);
    for(int i = 0; i < N; i++) cin >> C[i] >> P[i];

    // 累積和
    vector<int> sum1(N+1), sum2(N+1);
    for(int i = 0; i < N; i++){
        sum1[i + 1] = sum1[i];
        sum2[i + 1] = sum2[i];
        if(C[i] == 1) sum1[i + 1] += P[i];
        if(C[i] == 2) sum2[i + 1] += P[i];
    }

    int Q;
    cin >> Q;
    while(Q--){
        int L, R; cin >> L >> R;
        L--; // 半開区間にするため調整
        cout << sum1[R] - sum1[L] << " " << sum2[R] - sum2[L] << endl;
    }
    return 0;
}