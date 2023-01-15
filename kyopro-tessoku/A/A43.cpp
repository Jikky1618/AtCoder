#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, L;
    cin >> N >> L;
    vector<int> A(N);
    vector<char> B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        if(B[i] == 'W') ans = max(ans, A[i]);
        if(B[i] == 'E') ans = max(ans, L - A[i]);
    }

    cout << ans << endl;
}