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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int G = 0;
    for(int i = 0; i < N; i++) G = gcd(G, A[i]);

    bool flag = false;
    for(int i = 0; i < N; i++){
        if(A[i] >= K){
            if((A[i] - K) % G == 0) flag = true;
        }
    }

    cout << (flag ? "POSSIBLE" : "IMPOSSIBLE") << endl;
}