#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int Max = max_element(p.begin(), p.end()) - p.begin();
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(i == Max) ans += p[i] / 2;
        else ans += p[i];
    }

    cout << ans << endl;
    return 0;
}