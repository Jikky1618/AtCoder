#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    for(int i = 111; i <= 999; i += 111){
        if(N <= i){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}