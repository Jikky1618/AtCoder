#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 累積Max
    vector<int> left(n + 1), right(n + 1);
    for(int i = 0; i < n; i++) left[i + 1] = max(left[i], a[i]);
    for(int i = 0; i < n; i++) right[i + 1] = max(right[i], a[n - i - 1]);

    for(int i = 0; i < n; i++){
        cout << max(left[i], right[n-i-1]) << endl;
    }
    return 0;
}