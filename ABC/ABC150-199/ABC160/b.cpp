#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;

    int joy = 0;
    joy += x / 500 * 1000; // 500yen
    x %= 500;
    joy += x / 5 * 5; // 5yen;

    cout << joy << endl;

    return 0;
}