#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w,n;
    cin >> h >> w >> n;

    vector<vector<int>> sum(h+1,vector<int>(w+1));
    for(int i = 0; i < n; i++){
        int a,b,c,d; cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        sum[a][b] += 1;
        sum[a][d + 1] -= 1;
        sum[c + 1][b] -= 1;
        sum[c + 1][d + 1] += 1;
    }

    for(int i = 0; i < h; i++){
        for(int j = 1; j < w; j++){
            sum[i][j] += sum[i][j-1];
        }
    }
    for(int j = 0; j < w; j++){
        for(int i = 1; i < h; i++){
            sum[i][j] += sum[i-1][j];
        }
    }
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}