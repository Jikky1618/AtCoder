#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B, C;
    cin >> A >> B >> C;

    if(A - B == C && A + B == C) cout << "?" << endl;
    else if(A - B == C) cout << "-" << endl;
    else if(A + B == C) cout << "+" << endl;
    else cout << "!" << endl;
    return 0;
}