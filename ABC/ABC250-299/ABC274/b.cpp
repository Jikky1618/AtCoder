#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    vector<int> x(w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '#') x[j]++;
        }
    }

    for(auto && ans: x) cout << ans << endl;

    return 0;
}