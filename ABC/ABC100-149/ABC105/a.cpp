#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    if(N % K == 0){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }
    return 0;
}