#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int X, Y, Z;
    cin >> X >> Y >> Z;
    
    for(int i = 0; i < X; i++){
        if(X < i * Y + (i - 1) * Z + 2 * Z){
            cout << i - 1 << endl;
            return 0;
        }
    }
    return 0;
}