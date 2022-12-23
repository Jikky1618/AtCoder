#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    int K;
    cin >> S >> K;

    int N = S.size();
    vector<int> Sum(N + 1);
    for(int i = 0; i < N; i++) Sum[i + 1] = Sum[i] + (S[i] == '.' ? 1 : 0);
    
    int ans = 0, r = 0;
    for(int l = 0; l < N; l++){
        while(r < N && Sum[r + 1] - Sum[l] <= K){
            r++;
        }
        ans = max(ans, r - l);
    }

    cout << ans << endl;
    return 0;
}