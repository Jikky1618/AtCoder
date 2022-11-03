#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];

    int Max = *max_element(l.begin(),l.end());
    int Sum = 0;
    for(int i = 0; i < n; i++) Sum += l[i];
    Sum -= Max;

    if(Max < Sum) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}