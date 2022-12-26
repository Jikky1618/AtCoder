#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool is_palindrome(const string& s){
    return equal(s.begin(), s.end(), s.rbegin());
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B;
    cin >> A >> B;

    int ans = 0;
    for(int i = A; i <= B; i++){
        string S = to_string(i);
        if(is_palindrome(S)) ans++;
    }

    cout << ans << endl;
    return 0;
}