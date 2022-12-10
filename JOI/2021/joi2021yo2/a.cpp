#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A;
    string S;
    cin >> N >> A >> S;

    S = 'X' + S + 'X';
    // dir -1: 左, 1: 右
    int cnt = count(S.begin(), S.end(), '#'), dir = 1, pos = A, l = A, r = A;
    ll ans = 0;
    while(cnt > 0){
        if(dir == 1){
            if(cnt > 0) ans += r - pos, pos = r;
            ans++, pos++;
            if(pos <= N) r = pos;

            if(S[pos] == 'X' || S[pos] == '#'){
                dir = -1;
                if(S[pos] == '#') cnt--, S[pos] = '.';
            }
        }
        else if(dir == -1){
            if(cnt > 0) ans += pos - l, pos = l;
            ans++, pos--;
            if(0 < pos) l = pos;

            if(S[pos] == 'X' || S[pos] == '#'){
                dir = 1;
                if(S[pos] == '#') cnt--, S[pos] = '.';
            }
        }
    }

    cout << ans << endl;
    return 0;
}