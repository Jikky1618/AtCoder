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

    vector<int> ans(2 * n + 1);
    for(int i = 0; i < n; i++){
        ans[2 * i + 1] = ans[a[i] - 1] + 1;
        ans[2 * i + 2] = ans[a[i] - 1] + 1;
    }

    for(auto &&i: ans) cout << i << endl;
    return 0;
}