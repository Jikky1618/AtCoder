#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    string R, C;
    cin >> R >> C;

    string s = "ABC";
    s.resize(N, '.');
    sort(s.begin(), s.end());

    // 行のマスであり得るものを先に列挙しておく
    vector<string> V;
    do{
        V.emplace_back(s);
    }while(next_permutation(s.begin(), s.end()));

    vector<string> G(N, string(N, '.'));
    // G が条件を満たすか
    auto check = [&]() -> bool {
        string x, y;
        for(int i = 0; i < N; i++){
            // i 行目の最も左にある文字を探す
            for(int j = 0; j < N; j++){
                if(G[i][j] == '.') continue;
                x += G[i][j];
                break;
            }
        }
        for(int j = 0; j < N; j++){
            // j 列目の最も上にある文字を探す
            for(int i = 0; i < N; i++){
                if(G[i][j] == '.') continue;
                y += G[i][j];
                break;
            }
        }
        if(x != R || y != C) return false;
        // 各列に ABC が含まれているか調べる
        for(int j = 0; j < N; j++){
            vector<int> cnt(3);
            for(int i = 0; i < N; i++){
                if(G[i][j] == '.') continue;
                cnt[G[i][j] - 'A']++;
            }
            if(cnt[0] != 1 || cnt[1] != 1 || cnt[2] != 1) return false;
        }
        return true;
    };

    auto dfs = [&](auto&& self, int pos) -> void {
        if(pos == N){
            if(check()){
                cout << "Yes" << '\n';
                for(int i = 0; i < N; i++) cout << G[i] << '\n';
                exit(0);
            }
            return;
        }
        for(auto&& nx: V){
            char f = '.'; // f := nx の最も左にある文字
            for(int i = 0; i < N; i++){
                if(nx[i] == '.') continue;
                f = nx[i];
                break;
            }
            if(f != R[pos]) continue; // R[pos] でないなら枝刈り
            G[pos] = nx;
            self(self, pos + 1);
            G[pos] = string(N, '.');
        }
    };
    dfs(dfs, 0);

    cout << "No" << '\n';
}