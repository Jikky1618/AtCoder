#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q;
    string s;
    cin >> n >> q >> s;
    vector<int> l(q),r(q);
    for(int i = 0; i < q; i++) cin >> l[i] >> r[i];

    vector<int> ac(n + 1);
    for(int i = 1; i <= n; i++){
        if(s[i - 1] == 'A' && s[i] == 'C') ac[i]++;
    }

    vector<int> ps(n + 1);
    ps[0] = 0;
    for(int i = 0; i < n; i++) ps[i + 1] = ps[i] + ac[i + 1];

    for(int i = 0; i < q; i++){
        cout << ps[r[i] - 1] - ps[l[i] - 1] << endl;
    }

    // for(int i = 0; i < n; i++) debug(ps[i]);
    return 0;
}