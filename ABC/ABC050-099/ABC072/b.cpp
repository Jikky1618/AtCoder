#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;

    int N = s.size();
    for(int i = 0; i < N; i++) if(i % 2 == 0) cout << s[i];
    cout << endl;
    return 0;
}