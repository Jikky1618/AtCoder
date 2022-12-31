#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> X(M), Y(M);
    for(int i = 0; i < M; i++) cin >> X[i] >> Y[i];

    vector<int> ans(N);
    iota(ans.begin(), ans.end(), 1);
    for(int i = 0; i < M; i++){
        ans[X[i] - 1] = Y[i];
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}