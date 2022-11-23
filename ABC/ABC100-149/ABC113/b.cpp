#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,t,a;
    cin >> n >> t >> a;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    int ans = 0, diff = INF;
    for(int i = 0; i < n; i++){
        int val = abs((t * 1000 - h[i] * 6) - a * 1000);
        if(val < diff){
            diff = val, ans = i + 1;
        }
    }

    cout << ans << endl;
    return 0;
}