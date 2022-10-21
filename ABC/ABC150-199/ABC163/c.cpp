#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n - 1);
    for(auto &&i: a) cin >> i;

    vector<int> ans(n);
    for(int i = 0; i < n - 1; i++) ans[a[i] - 1]++;

    for(auto &&i: ans) cout << i << endl;
    return 0;
}