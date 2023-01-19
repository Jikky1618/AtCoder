#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int A; cin >> A, A--;
        G[A].push_back(i + 1);
    }

    vector<int> dp(N); // dp[i] :- 社員iの部下の人数
    for(int i = N - 1; i >= 0; i--){
        for(auto next: G[i]){
            dp[i] += (dp[next] + 1);
        }
    }

    for(int i = 0; i < N; i++){
        cout << dp[i] << endl;
    }
}