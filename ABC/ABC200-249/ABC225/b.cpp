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
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int a, b; cin >> a >> b, a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool star = false;
    for(int i = 0; i < N; i++){
        int deg = G[i].size();
        if(deg == N - 1) star = true;
    }

    cout << (star ? "Yes" : "No") << endl;
}