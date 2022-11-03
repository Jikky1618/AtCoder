#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;
    string z = "ZONe";

    int ans = 0;
    for(int i = 0; i < s.size(); i++){
        string s2 = s.substr(i, 4);
        if(s2 == z) ans++;
    }

    cout << ans << endl;
    return 0;
}