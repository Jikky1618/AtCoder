#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> l(m),r(m);
    for(int i = 0; i < m; i++) cin >> l[i] >> r[i];

    int max_l = 0, min_r = INF;
    for(int i = 0; i < m; i++){
        max_l = max(max_l, l[i]);
        min_r = min(min_r, r[i]);
    }

    cout << max(0, min_r - max_l) << endl;
    return 0;
}