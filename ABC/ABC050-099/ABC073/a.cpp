#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string N;
    cin >> N;
    cout << (N.find('9') != string::npos ? "Yes" : "No") << endl;
    return 0;
}