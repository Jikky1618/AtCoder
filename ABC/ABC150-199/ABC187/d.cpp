#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // 差に注目して貪欲法
    ll diff = 0; // 高橋 - 青木 の票数
    vector<ll> D(N);
    for(int i = 0; i < N; i++){
        diff -= A[i];
        D[i] = A[i] + A[i] + B[i]; // 演説すると変化する票数の差
    }

    sort(D.begin(), D.end());

    int ans = 0;
    while(diff <= 0){
        diff += D.back(); D.pop_back();
        ans++;
    }

    cout << ans << endl;
    return 0;
}