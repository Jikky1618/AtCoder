#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    int N = S.size();
    bool flag = (S == "keyence" ? true : false);
    for(int l = 0; l < N; l++){
        for(int r = l; r < N; r++){
            string T; // make
            for(int i = 0; i < N; i++){
                if(l <= i && i <= r) continue;
                T += S[i];
            }

            if(T == "keyence") flag = true;
        }
    }

    cout << (flag ? "YES" : "NO") << endl;
}