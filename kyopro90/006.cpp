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
    int N, K;
    string S;
    cin >> N >> K >> S;

    // pos[i][c] := i番目以降に最初に文字cが登場するindex
    // 登場しないときはN
    vector<vector<int>> pos(N + 1, vector<int>(26, N));
    for(int i = N - 1; i >= 0; i--){
        pos[i] = pos[i + 1];
        pos[i][S[i] - 'a'] = i;
    }

    string ans = "";
    int current_pos = -1;
    for(int i = 0; i < K; i++){
        for(char c = 'a'; c <= 'z'; c++){
            // current_pos番目以降で最初に文字cが登場するindex
            int j = pos[current_pos + 1][c - 'a'];

            // jまで進んだとき K - i文字以上あるかを確認(なければK文字にできない)
            if(N - j >= K - i){
                ans += c;
                current_pos = j;
                break;
            }
        }
    }

    cout << ans << endl;
}