#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<29;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    int ans = INF;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j && ans > a[i] + b[j]) ans = a[i] + b[j];
            else if(i != j && ans > max(a[i],b[j])) ans = max(a[i],b[j]);
        }
    }

    cout << ans << endl;

    return 0;
}