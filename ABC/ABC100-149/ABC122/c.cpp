#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q;
    string s;
    cin >> n >> q >> s;

    vector<int> ac(n + 1);
    for(int i = 0; i < n; i++){
        if(s[i] == 'A' && s[i + 1] == 'C') ac[i]++;
    }

    vector<int> sum(n + 1);
    sum[0] = 0;
    for(int i = 0; i < n; i++) sum[i + 1] = sum[i] + ac[i];

    for(int i = 0; i < q; i++){
        int l,r; cin >> l >> r;
        l--; r--;
        cout << sum[r] - sum[l] << endl;
    }

    return 0;
}