#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(find(B.begin(), B.end(), A[i]) != B.end()) ans++;
    }

    cout << ans << endl;
    return 0;
}