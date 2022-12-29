#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S, T;
    cin >> S >> T;

    int N = S.size();
    int x = 0, y = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'L') x--;
        if(S[i] == 'R') x++;
        if(S[i] == 'U') y++;
        if(S[i] == 'D') y--;
        if(S[i] == '?') cnt++;
    }

    int dist = abs(x) + abs(y);
    if(T == "1") cout << dist + cnt << endl;
    else cout << (dist >= cnt ? dist - cnt : abs(dist - cnt) % 2) << endl;
    return 0;
}