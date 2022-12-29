#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string N;
    cin >> N;
    if((N[0] == N[1] && N[1] == N[2]) || (N[1] == N[2] && N[2] == N[3])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}