#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<string> s(N);
    for(int i = 0; i < N; i++) cin >> s[i];

    vector<string> S(N); // ans
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            S[i].push_back(s[N - j - 1][i]);
        }
    }

    for(int i = 0; i < N; i++) cout << S[i] << endl;
    return 0;
}