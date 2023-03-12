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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i]--;

    vector<int> flag(N);
    for(int i = 0; i < N; i++) if(flag[i] == 0) flag[A[i]] = 1;
    
    vector<int> ans;
    for(int i = 0; i < N; i++) if(flag[i] == 0) ans.push_back(i + 1);

    cout << ans.size() << endl;
    for(auto e: ans) cout << e << endl;
}