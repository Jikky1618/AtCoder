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

    for(int i = 0; i < N; i++){
        cout << S[i];
        if(i != N - 1 && S[i] == 'n' && S[i + 1] == 'a'){
            cout << 'y'; // yを挿入
        }
    }
    cout << endl;
}