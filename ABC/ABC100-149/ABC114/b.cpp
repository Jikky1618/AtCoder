#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int ans = INF;
    for(int i = 0; i < s.size() - 2; i++){
        int num = stoi(s.substr(i, 3));
        int diff = abs(num - 753);
        ans = min(ans, diff);
    }

    cout << ans << endl;
    return 0;
}