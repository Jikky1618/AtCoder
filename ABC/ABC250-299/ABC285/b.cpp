#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;

    for(int i = 1; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < N; j++){
            if(j + i < N && S[j] != S[j + i]) cnt++;
            else break;
        }
        cout << cnt << endl;
    }
}