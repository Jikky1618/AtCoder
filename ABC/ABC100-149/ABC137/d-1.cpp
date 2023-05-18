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
    debug(V);
    
    multiset<int> ms;
    int ans = 0;
    for(int i = 0; i < M; i++){
        for(auto e: V[i]) ms.insert(e);
        if(!ms.empty()){
            int val = *ms.rbegin();
            ms.erase(ms.find(val));
            ans += val;
        }
    }

    cout << ans << endl;
}