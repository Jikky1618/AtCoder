#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    string ans = "";
    while(N > 0){
        N--;
        char c = ((N % 26) + 'a');
        ans = c + ans;
        N /= 26;
    }

    cout << ans << endl;
    return 0;
}