#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    int N;
    cin >> S >> N;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i * 5 + j == N - 1) cout << S[i] << S[j] << endl;
        }
    }

    return 0;
}