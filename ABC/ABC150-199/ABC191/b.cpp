#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    auto itEnd = remove(a.begin(), a.end(),x);
    a.erase(itEnd,a.end());

    for(int i = 0; i < a.size(); i++) cout << a[i] << " ";
    cout << endl;

    return 0;
}