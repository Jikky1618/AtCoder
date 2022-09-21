#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<string> tiles(n,string(n,'.')); // タイルの色用配列
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i + j) % 2 == 1) tiles[i][j] = '#'; // parityで白か黒かを判別
        }
    }

    vector<string> x(n*a,string(n*b,'.')); // 実際のタイル配列
    for(int i = 0; i < n*a; i++){
        for(int j = 0; j < n*b; j++){
            x[i][j] = tiles[i/a][j/b];
        }
    }

    for(int i = 0; i < n*a; i++){
        for(int j = 0; j < n*b; j++) cout << x[i][j];
        cout << endl;
    }

    return 0;
}