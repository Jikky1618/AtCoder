#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // 縦
            if(i + 5 < n){
                cnt = 0;
                for(int k = 0; k < 6; k++){
                    if(s[i + k][j] == '#') cnt++;
                }
                if(4 <= cnt) flag = true;
            }
            // 横
            if(j + 5 < n){
                cnt = 0;
                for(int k = 0; k < 6; k++){
                    if(s[i + k][j] == '#') cnt++;
                }
                if(4 <= cnt) flag = true;
            }
            // 斜め(左上、左下)
            if(i + 5 < n && j + 5 < n){
                for(int k = 0; k < 6; k++){
                    if(s[i + k][j + k] == '#') cnt++;
                }
                if(4 <= cnt) flag = true;
            }
            // 斜め(右下、左上)
            if(0 <= i - 5 && j + 5 < n){
                for(int k = 0; k < 6; k++){
                    if(s[i - k][j + k] == '#') cnt++;
                }
                if(4 <= cnt) flag = true;
            }
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}