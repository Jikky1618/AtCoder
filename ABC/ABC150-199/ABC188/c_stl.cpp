#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(1 << n);
    for(int i = 0; i < (1 << n); i++) cin >> a[i];

    int half = (1 << (n - 1));
    auto Max1 = max_element(a.begin(), a.end() - half);
    auto Max2 = max_element(a.begin() + half, a.end());

    int ans = *Max1 > *Max2 ? Max2 - a.begin() + 1 : Max1 - a.begin() + 1;
    cout << ans << endl;
    return 0;
}