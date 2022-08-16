#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    sort(c.begin(), c.end());
    ll count = 1;
    for(int i = 0; i < n; i++){
        count *= max(0,c[i] - i);
        count %= MOD;
    }
    cout << count << endl;

    return 0; 
}