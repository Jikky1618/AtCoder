#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 平方数かどうかの判定
bool is_square(ll N) {
    ll r = (ll)floor(sqrt((ll)N));  // 切り捨てした平方根
    return (r * r) == N;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string a, b;
    cin >> a >> b;

    int N = stoi(a + b);
    if(is_square(N)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}