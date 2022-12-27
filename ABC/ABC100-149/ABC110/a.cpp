#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> N(3);
    for(int i = 0; i < 3; i++) cin >> N[i];

    sort(N.begin(), N.end(), greater<int>());
    cout << N[0] * 10 + N[1] + N[2] << endl;
    return 0;
}