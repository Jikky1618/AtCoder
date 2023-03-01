#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MAX = 1010;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector imos(MAX + 1, vector<int>(MAX + 1));
    for(int i = 0; i < N; i++){
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        imos[rx][ry]++;
        imos[lx][ry]--;
        imos[lx][ly]++;
        imos[rx][ly]--; 
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) imos[i + 1][j] += imos[i][j];
    }

    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++) imos[i][j + 1] += imos[i][j];
    }

    vector<int> ans(N);
    
    for(auto v: imos){
        for(auto e: v){
            if(e) ans[e - 1]++;
        }
    }

    for(int i = 0; i < N; i++){
        cout << ans[i] << "\n";
    }
}