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

    for(int i = 0; i < N; i++){
        int l, r; cin >> l >> r; l--;
        reverse(S.begin() + l, S.begin() + r);
    }

    cout << S << endl;
    return 0;
}