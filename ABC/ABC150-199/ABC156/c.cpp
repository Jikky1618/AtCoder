#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];

    int ans = INF;
    for(int p = 1; p <= 100; p++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += pow(x[i] - p, 2);
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;
    return 0;
}