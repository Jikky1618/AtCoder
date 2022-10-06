#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int ans = 0;
    for(int i = 1; i < n - 1; i++){
        if((p[i - 1] < p[i] && p[i] < p[i + 1]) || (p[i + 1] < p[i] && p[i] < p[i - 1])){
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}