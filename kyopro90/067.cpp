#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n_to_dec(string x,ll n){ // n進数のxを10進数に変換
    ll ans = 0, base = 1, size = x.size();
    for(int i = size - 1; i >= 0; i--){
        ans += 1LL * (x[i] - '0') * base;
        base *= n;
    }
    return ans;
}

string dec_to_n(ll num, ll n){ // 10進数のnumをn進数に変換
    if(num == 0) return "0";
    string ans;
    while(num > 0){
        char c = ((num % n) + '0');
        ans = c + ans;
        num /= n;
    }
    return ans;
}

string drc(string str, int n, int m){ // n進数のstrをm進数に変換
    return dec_to_n(n_to_dec(str, n), m);
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string N;
    int K;
    cin >> N >> K;

    string Ans = N;
    for(int i = 0; i < K; i++){
        Ans = drc(Ans, 8, 9);
        for(auto &&s: Ans) if(s == '8') s = '5';
    }

    cout << Ans << endl;
    return 0;
}