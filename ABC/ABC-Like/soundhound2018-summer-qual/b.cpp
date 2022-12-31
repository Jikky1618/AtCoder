#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    int w;
    cin >> S >> w;

    int N = S.size();
    string ans;
    for(int i = 0; i < N; i++){
        if(i % w == 0) ans.push_back(S[i]);
    }

    cout << ans << endl;
    return 0;
}