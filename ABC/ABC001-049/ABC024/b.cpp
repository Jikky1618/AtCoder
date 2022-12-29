#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(i < N - 1 && A[i] + T >= A[i + 1]) ans += A[i + 1] - A[i];
        else ans += T;
    }

    cout << ans << endl;
    return 0;
}