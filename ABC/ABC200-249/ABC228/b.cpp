#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<bool> flag(N, false);
    for(int i = 0; i < N; i++){
        flag[X-1] = true;
        X = A[X-1];
    }

    int ans = 0;
    for(int i = 0; i < N; i++) if(flag[i]) ans++;

    cout << ans << endl;
    return 0;
}