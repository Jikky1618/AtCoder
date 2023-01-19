#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    stack<pair<int, int>> stk;
    for(int i = 0; i < N; i++){
        if(i > 0){
            stk.push({i, A[i - 1]});
            while(!stk.empty() && stk.top().second <= A[i]){
                stk.pop();
            }
        }
        int ans = (stk.empty() ? -1 : stk.top().first);

        cout << ans << " \n"[i == N - 1];
    }
}