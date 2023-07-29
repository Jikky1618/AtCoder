#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<string> Tak = {
    "###.?????",
    "###.?????",
    "###.?????",
    "....?????",
    "?????????",
    "?????....",
    "?????.###",
    "?????.###",
    "?????.###"
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    auto check = [&](int x, int y) -> bool { 
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(Tak[i][j] == '?') continue;
                if(S[i + x][j + y] != Tak[i][j]) return false;
            }
        }

        return true;
    };

    for(int i = 0; i + 9 <= N; i++){
        for(int j = 0; j + 9 <= M; j++){
            if(check(i, j)){
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}