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
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<int> flag(N * M + 1);
    for(int i = 0; i < N; i++){
        int val = i * M;
        flag[val] = true;
        for(int j = 0; j < M; j++){
            val += N - i, val -= i;
            flag[val] = true;
        }
    }

    cout << (flag[K] ? "Yes" : "No") << endl;
}