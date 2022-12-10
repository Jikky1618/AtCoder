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

    for(int i = 0; i < N - 1; i++){
        if(S[i] == S[i+1]){
            S[i] = toupper(S[i]), S[i+1] = toupper(S[i+1]);
        }
    }

    cout << S << endl;
    return 0;
}