#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 90度回転
vector<string> rot(vector<string> grid){
    int n = grid.size();
    vector<string> res(n, string(n,'.'));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res[i][j] = grid[n - 1 - j][i];
        }
    }
    return res;
}

void left_top(vector<string> &grid,int &x,int &y){
    int n = grid.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '#'){
                x = min(x,i), y = min(y,j);
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<string> s(n),t(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n; i++) cin >> t[i];


    // #の数が異なればNo
    int cnt_s = 0, cnt_t = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '#') cnt_s++;
            if(t[i][j] == '#') cnt_t++;
        }
    }
    if(cnt_s != cnt_t){
        cout << "No" << endl;
        return 0;
    }

    // 4回判定
    for(int i = 0; i < 4; i++){
        int sx = n, sy = n, tx = n, ty = n;
        left_top(s, sx, sy);
        left_top(t, tx, ty);

        bool flag = true;
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                if( n <= sx+x || n <= sy+y || n <= tx+x || n <= ty+y) continue;
                if(s[sx+x][sy+y] != t[tx+x][ty+y]) flag = false;
            }
        }

        if(flag){
            cout << "Yes" << endl;
            return 0; 
        }
        s = rot(s);
    }

    cout << "No" << endl;
    return 0;
}