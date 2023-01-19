#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    auto dfs = [&](int pos, string S, auto self) -> void {
        if(pos == N){
            cout << S << "\n";
            return;
        }

        for(int i = 0; i < 3; i++){
            self(pos + 1, S + (char)(i + 'a'), self);
        }
    };

    dfs(0, "", dfs);
}