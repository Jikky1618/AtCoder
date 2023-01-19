#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<string> S(3);
    for(int i = 0; i < 3; i++) cin >> S[i];
    string T;
    cin >> T;

    int N = T.size();
    string ans;
    for(int i = 0; i < N; i++){
        ans += S[T[i] - '0' - 1];
    }
    
    cout << ans << endl;
}