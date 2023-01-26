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

    vector imos(1511, vector<int>(1511));
    for(int i = 0; i < N; i++){
        int A, B, C, D; cin >> A >> B >> C >> D;
        imos[A][B]++;
        imos[A][D]--;
        imos[C][B]--;
        imos[C][D]++;
    }
    for(int i = 0; i < 1510; i++){
        for(int j = 0; j < 1510; j++){
            imos[i + 1][j] += imos[i][j];
        }
    }
    for(int i = 0; i < 1510; i++){
        for(int j = 0; j < 1510; j++){
            imos[i][j + 1] += imos[i][j];
        }
    }
    

    int ans = 0;
    for(int i = 0; i < 1510; i++){
        for(int j = 0; j < 1510; j++){
            if(imos[i][j]) ans++;
        }
    }

    cout << ans << endl;
}