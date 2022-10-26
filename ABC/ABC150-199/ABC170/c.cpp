#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x,n;
    cin >> x >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int ans = INF;
    for(int np = 0; np < 102; np++){
        bool found = false;
        for(int i = 0; i < n; i++) if(p[i] == np) found = true;
        if(found) continue;
        if(abs(ans - x) > abs(np - x)) ans = np;
    }

    cout << ans << endl;
    return 0;
}