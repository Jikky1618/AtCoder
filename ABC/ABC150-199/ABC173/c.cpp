#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w,k;
    cin >> h >> w >> k;
    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    int ans = 0;
    for(int bitH = 0; bitH < (1 << h); bitH++){
        for(int bitW = 0; bitW < (1 << w); bitW++){
            int cnt = 0;
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    if(!((bitH >> i) & 1)) continue;
                    if(!((bitW >> j) & 1)) continue;
                    if(grid[i][j] == '#') cnt++;
                }
            }
            if(cnt == k) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}