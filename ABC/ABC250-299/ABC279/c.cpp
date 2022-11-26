#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int h,w;
    cin >> h >> w;
    vector<string> s(h),t(h);
    for(int i = 0; i < h; i++) cin >> s[i];
    for(int i = 0; i < h; i++) cin >> t[i];


    for(int i = 0; i < h; i++){
        sort(s[i].begin(), s[i].end());
        sort(t[i].begin(), t[i].end());
    }

    bool flag = true;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(s[i][j] != t[i][j]) flag = false;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}