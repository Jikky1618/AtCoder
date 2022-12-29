#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<string> C(2);
    for(int i = 0; i < 2; i++) cin >> C[i];

    vector<string> tmp = C;
    for(int i = 0; i < 2; i++) reverse(tmp[i].begin(), tmp[i].end());
    reverse(tmp.begin(), tmp.end());

    cout << (C == tmp ? "YES" : "NO") << endl;
    return 0;
}