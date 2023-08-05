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
    vector<vector<int>> G(N);
    vector<int> deg(N);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B, A--, B--;
        deg[B]++;
    }

    bool flag = count(deg.begin(), deg.end(), 0) == 1;

    if(flag){
        int ans = 0;
        for(int i = 0; i < N; i++) if(deg[i] == 0) ans = i + 1;
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }
}