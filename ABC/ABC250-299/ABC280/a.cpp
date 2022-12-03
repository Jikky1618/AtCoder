#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i = 0; i < h; i++) cin >> s[i];

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] == '#') ans++;
        }
    }

    cout << ans << endl;
    return 0;
}