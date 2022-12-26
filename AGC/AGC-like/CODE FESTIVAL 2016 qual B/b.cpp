#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;

    int cnt = 0, cntB = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'a'){
            if(cnt < A + B){
                cout << "Yes" << endl;
                cnt++;
            }
            else cout << "No" << endl;
        }
        if(S[i] == 'b'){
            if(cnt < A + B && cntB < B){
                cout << "Yes" << endl;
                cnt++, cntB++;
            }
            else cout << "No" << endl;
        }
        if(S[i] == 'c') cout << "No" << endl;
    }
    return 0;
}