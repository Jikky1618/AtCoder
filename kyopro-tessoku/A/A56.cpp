#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct RollingHash {
    static const ll base = 10007;
    static const ll mod = 1e9 + 7;
    vector<ll> hash, power;

    RollingHash(const string &S){
        int _n = (int)S.size();
        hash.assign(_n+1, 0), power.assign(_n+1, 1);
        for(int i = 0; i < _n; i++){
            hash[i + 1] = (hash[i] * base + S[i]) % mod;
            power[i + 1] = (power[i] * base) % mod;
        }
    }

    // S[l:r] のハッシュ値を取得
    inline ll get(int l, int r) const {
        ll val = hash[r] - hash[l] * power[r - l] % mod;
        if(val < 0) val += mod;
        return val;
    }

    // S のハッシュ値を取得
    inline ll get() const {
        ll val = hash.back() % mod;
        return val;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    RollingHash rh(S);
    while(Q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, c--;
        cout << (rh.get(a, b) == rh.get(c, d) ? "Yes" : "No") << endl; 
    }
}