#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    string S;
    cin >> S;

    for(int i = 0; i < N - 1; i++){
        if(S[i + 1] == 'J') cout << S[i] << endl;
    }
    return 0;
}