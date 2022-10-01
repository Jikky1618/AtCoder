#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,q;
    cin >> n >> q;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++){
        int l; cin >> l;
        a[i].resize(l);
        for(int j = 0; j < l; j++){
            cin >> a[i][j];
        }
    }
    vector<int> s(q),t(q);
    for(int i = 0; i < q; i++) cin >> s[i] >> t[i];

    for(int i = 0; i < q; i++){
        cout << a[s[i] - 1][t[i] - 1] << endl;
    }

    return 0;
}