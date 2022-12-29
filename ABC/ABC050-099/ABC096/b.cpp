#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> A(3);
    for(int i = 0; i < 3; i++) cin >> A[i];
    int K;
    cin >> K;

    sort(A.begin(), A.end(), greater<int>());
    for(int i = 0; i < K; i++) A[0] *= 2;

    int ans = 0;
    for(int i = 0; i < 3; i++) ans += A[i];

    cout << ans << endl;
    return 0;
}