#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector A(4, vector<int>(4));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cin >> A[i][j];
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
                if(A[i][j] == A[nx][ny]){
                    cout << "CONTINUE" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "GAMEOVER" << endl;
}