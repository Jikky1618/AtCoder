#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, A, B;
    cin >> N >> A >> B;

    ll Min = A * (N - 1) + B;
    ll Max = A + B * (N - 1);
    cout << max(0LL, Max - Min + 1) << endl;
}