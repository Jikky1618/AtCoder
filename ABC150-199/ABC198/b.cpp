#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string n;
    cin >> n;

    while(n[n.size() - 1] == '0') n.pop_back();
    string n_rev = n;
    reverse(n_rev.begin(),n_rev.end());

    if(n == n_rev) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}