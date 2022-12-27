#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    bool flag = false;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i * 4 + 7 * j == N) flag = true;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}