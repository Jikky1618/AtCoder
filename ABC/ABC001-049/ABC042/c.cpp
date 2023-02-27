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
    vector<char> D(K);
    for(int i = 0; i < N; i++) cin >> D[i];

    for(int i = N; i <= 10 * N; i++){
        string S = to_string(i);
        bool flag = true;

        for(auto c: S){
            for(auto d: D){
                if(c == d) flag = false;
            }
        }

        if(flag){
            cout << S << endl;
            break;
        }
    }
}