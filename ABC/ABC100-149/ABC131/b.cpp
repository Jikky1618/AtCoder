#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,l;
    cin >> n >> l;
    vector<int> taste(n);
    for(int i = 0; i < n; i++) taste[i] = l + i;
    
    int eat = INF;
    for(int i = 0; i < n; i++){
        if(abs(eat) > abs(taste[i])) eat = taste[i];
    }
    debug(eat);

    int ans = 0;
    for(int i = 0; i < n; i++) ans += taste[i];
    ans -= eat;

    cout << ans << endl;
    return 0;
}