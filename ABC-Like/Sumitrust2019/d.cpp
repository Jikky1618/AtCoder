#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                int si = -1,sj = -1,sk = -1;
                for(int x = 0; x < n; x++){
                    if(s[x] == i + '0' && si == -1) si = x;
                    else if(s[x] == j + '0' && sj == -1 && si != -1) sj = x;
                    else if(s[x] == k + '0' && sk == -1 && sj != -1) sk = x;
                }
                if(si != -1 && sj != -1 && sk != -1) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}