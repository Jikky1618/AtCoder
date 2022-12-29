#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int L, H, N;
    cin >> L >> H >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i < N; i++){
        if(A[i] < L) cout << L - A[i] << endl;
        else if(H < A[i]) cout << -1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}