#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    ll k;
    cin >> s >> k;
    
    for(int i = 0; i < min((ll)s.size(), k); i++){
        if(s[i] != '1'){
            cout << s[i] << endl;
            return 0;
        }
    }

    cout << 1 << endl;
    return 0;
}