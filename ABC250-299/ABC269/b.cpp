#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<string> grid(10);
    for(int i = 0; i < 10; i++) cin >> grid[i];
    

    int a = -1,b = -1,c = -1,d = -1;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            // 左上
            if(grid[i][j] == '#' && a == -1 && c == -1){
                a = i + 1; c = j + 1; break;
            }
        }
    }

    for(int i = 9; i >= 0; i--){
        for(int j = 9; j >= 0; j--){
            // 右下
            if(grid[i][j] == '#' && b == -1 && d == -1){
                b = i + 1; d = j + 1; break;
            }
        }
    }
    
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    
    return 0;
}