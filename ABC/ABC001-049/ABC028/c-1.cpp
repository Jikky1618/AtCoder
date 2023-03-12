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
    vector<int> V(5);
    for(int i = 0; i < 5; i++) cin >> V[i];
    
    vector<int> N;
    for(int i = 0; i < 5; i++){
        for(int j = i + 1; j < 5; j++){
            for(int k = j + 1; k < 5; k++){
                N.push_back(V[i] + V[j] + V[k]);
            }
        }
    }

    // 座標圧縮
    sort(N.begin(), N.end(), greater<int>());
    N.erase(unique(N.begin(), N.end()), N.end());
    
    cout << N[2] << endl;
}