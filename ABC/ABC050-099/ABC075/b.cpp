#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
const vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];

    vector<string> ans(h);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#'){
                ans[i] += '#';
                continue;
            }

            int cnt = 0;
            for(int k = 0; k < 8; k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if(s[nx][ny] == '#') cnt++;
            }
            ans[i] += (cnt + '0');
        }
    }

    for(int i = 0; i < h; i++) cout << ans[i] << endl;
    return 0;
}