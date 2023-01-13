#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // dp[i] := i番目のLISの最小値
    vector<int> dp;

    for(int i = 0; i < N; i++){
        auto itr = lower_bound(dp.begin(), dp.end(), A[i]);
        if(itr == dp.end()){
            dp.push_back(A[i]);
        }else{
            *itr = A[i];
        }
    }
    
    int ans = dp.size();
    cout << ans << endl;
}