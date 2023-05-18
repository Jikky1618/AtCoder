#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i], A[i]--;

    vector<vector<int>> V(M);
    for(int i = 0; i < N; i++){
        if(A[i] < M) V[A[i]].emplace_back(B[i]);
    }

    int ans = 0;
    priority_queue<int> pq;
    for(int i = 0; i < M; i++){
        for(auto e: V[i]) pq.emplace(e);
        if(!pq.empty()){
            int val = pq.top(); pq.pop();
            ans += val;
        }
    }

    cout << ans << endl;
}