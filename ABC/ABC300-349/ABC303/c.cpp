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
    int N, M, H, K;
    cin >> N >> M >> H >> K;
    string S;
    cin >> S;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y;
        mp[{x, y}] = 1;
    }

    int x = 0, y = 0, h = H;
    for(int i = 0; i < N; i++){
        if(S[i] == 'R') x++;
        if(S[i] == 'L') x--;
        if(S[i] == 'U') y++;
        if(S[i] == 'D') y--;

        h--;
        if(h < 0){
            cout << "No" << endl;
            return 0;
        }
        if(mp[{x, y}] && h < K){
            h = K, mp[{x, y}] = 0;
        }
    }

    cout << "Yes" << endl;
}