#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    ll ans = 1;
    for(int i = 2; i <= N; i++) ans *= i;

    cout << ans + 1 << endl;
}