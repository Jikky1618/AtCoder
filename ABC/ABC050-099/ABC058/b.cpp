#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string O, E;
    cin >> O >> E;

    int N = O.size() + E.size();
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) cout << O[i / 2];
        if(i % 2 == 1) cout << E[i / 2];
    }
    cout << endl;
    return 0;
}