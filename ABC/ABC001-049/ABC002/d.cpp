#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector G(N, vector<bool>(N)); // 隣接行列
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y, x--, y--;
        G[x][y] = G[y][x] = true;
    }

    int ans = 0;
    for(int bit = 0; bit < (1 << N); bit++){
        vector<int> S; // 派閥
        for(int i = 0; i < N; i++){
            if((bit >> i) & 1){
                S.push_back(i);
            }
        }

        int cnt = S.size();
        bool flag = true;
        for(int i = 0; i < cnt; i++){
            for(int j = i + 1; j < cnt; j++){
                if(G[S[i]][S[j]] == false) flag = false;
            }
        }

        if(flag == true) ans = max(ans, cnt);
    }

    cout << ans << endl;
}