#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i  = 0; i < n; i++) cin >> s[i];
    int sum = 0;
    for(int i = 0; i < n; i++) sum += s[i];

    cout << sum << endl;
    return 0;
}