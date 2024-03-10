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
    int root = -1;
    for(int i = 0; i < N; i++){
        cin >> A[i], A[i]--;
        if(A[i] < 0) root = i;
    }
    // 人 i の後ろにいる人の番号
    vector<int> to(N);
    for(int i = 0; i < N; i++) if(root != i) to[A[i]] = i;
    debug(to);

    int x = root;
    vector<int> ans;
    for(int i = 0; i < N; i++){
        ans.emplace_back(x + 1);
        x = to[x];
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N - 1];
    }
}