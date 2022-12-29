#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Y;
    cin >> N >> Y;

    for(int x = 0; x <= N; x++){ // 10000
        for(int y = 0; y <= N - x; y++){ // 5000
            int z = (Y - 10000 * x - 5000 * y) / 1000;
            if(x + y + z == N){
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}