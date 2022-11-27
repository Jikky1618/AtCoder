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

    vector<string> Ts(w),Tt(w);
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            Ts[i].push_back(s[j][i]);
            Tt[i].push_back(t[j][i]);
        }
    }

    sort(Ts.begin(),Ts.end());
    sort(Tt.begin(),Tt.end());

    if(Ts == Tt) cout << "Yes" << endl;
    else cout << "No" << endl;
}
