#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];

    int ans = 0;
    for(int i = 0; i < h - 1; i++){
        for(int j = 0; j < w - 1; j++){
            int cnt = 0;
            for(int x = 0; x < 2; x++){
                for(int y = 0; y < 2; y++){
                    if(s[i + x][j + y] == '#') cnt++;
                }
            }
            if(cnt == 1 || cnt == 3) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}