#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;

    int N = s.size(), posA = INF, posZ = 0;
    for(int i = 0; i < N; i++){
        if(s[i] == 'A') posA = min(posA, i);
        if(s[i] == 'Z') posZ = max(posZ, i);
    }

    cout << posZ - posA + 1 << endl;
    return 0;
}