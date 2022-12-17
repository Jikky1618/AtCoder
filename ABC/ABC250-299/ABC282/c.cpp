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

    bool flag = false;
    for(int i = 0; i < N; i++){
        if(S[i] == '"') flag = !flag;
        if(flag == false && S[i] == ',') S[i] = '.';
    }

    cout << S << endl;
    return 0;
}