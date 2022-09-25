#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int d,t,s;
    cin >> d >> t >> s;
    cout << (s * t >= d ? "Yes" : "No") << endl;

    return 0;
}