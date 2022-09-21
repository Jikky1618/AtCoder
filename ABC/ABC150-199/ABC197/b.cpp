#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w,x,y;
    cin >> h >> w >> x >> y;
    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    int ans = 1; x--; y--;
    for(int i = 1; i < h; i++){
        if(x + i >= h || grid[x + i][y] == '#') break;
        else ans++;
    }
    for(int i = 1; i < h; i++){
        if(x - i < 0 || grid[x - i][y] == '#') break;
        else ans++;
    }
    for(int i = 1; i < w; i++){
        if(y + i >= w || grid[x][y + i] == '#') break;
        else ans++;
    }
    for(int i = 1; i < w; i++){
        if(y - i < 0 || grid[x][y - i] == '#') break;
        else ans++;
    }

    cout << ans << endl;

    return 0;
}