#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> x(N), y(M);
    for(int i = 0; i < N; i++) cin >> x[i];
    for(int i = 0; i < M; i++) cin >> y[i];

    bool war = true;
    for(int Z = X + 1; Z <= Y; Z++){
        bool flag = true;
        for(int i = 0; i < N; i++) if(x[i] >= Z) flag = false;
        for(int i = 0; i < M; i++) if(y[i] < Z) flag = false;
        if(flag) war = false;
    }

    if(war) cout << "War" << endl;
    else cout << "No War" << endl;
    return 0;
}