#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    cout << (2 * N - 2 <= K && K % 2 == (2 * N - 2) % 2 ? "Yes" : "No") << endl;
}