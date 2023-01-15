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

    bool flag = false;
    int cnt = 0;
    for(int i = 0; i < N - 1; i++){
        if(S[i] == S[i + 1]) cnt++;
        else cnt = 0;
        
        if(cnt == 2) flag = true;
    }

    cout << (flag ? "Yes" : "No") << endl;
}