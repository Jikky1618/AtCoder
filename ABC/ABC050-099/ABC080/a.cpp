#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A, B;
    cin >> N >> A >> B;
    cout << min(A * N, B) << endl;
    return 0;
}