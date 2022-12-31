#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    if(S.size() == 3) reverse(S.begin(), S.end());

    cout << S << endl;
    return 0;
}