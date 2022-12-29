#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string A, B;
    cin >> A >> B;
    cout << (A.size() > B.size() ? A : B) << endl;
    return 0;
}