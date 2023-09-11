#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<int MOD> struct modint {
    ll val;
    constexpr modint(ll x = 0): val(x % MOD) {
        if(val < 0) val += MOD;
    }
    constexpr int mod() const { return MOD; }
    constexpr modint operator + () const {
        return modint(val);
    }
    constexpr modint operator - () const {
        return modint(MOD - val);
    }
    constexpr modint& operator++() {
        return (*this) += 1;
    }
    constexpr modint& operator--() {
        return (*this) -= 1;
    }
    constexpr modint operator++(int) {
        modint x = (*this); ++(*this);
        return x;
    }
    constexpr modint operator--(int) {
        modint x = (*this); --(*this);
        return x;
    }
    constexpr modint operator + (const modint& x) const {
        return modint(*this) += x;
    }
    constexpr modint operator - (const modint& x) const {
        return modint(*this) -= x;
    }
    constexpr modint operator * (const modint& x) const {
        return modint(*this) *= x;
    }
    constexpr modint operator / (const modint& x) const {
        return modint(*this) /= x;
    }
    constexpr modint& operator += (const modint& x) {
        if((val += x.val) >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator -= (const modint& x) {
        if((val += MOD - x.val) >= MOD) val -= MOD;
        return *this;
    }
    constexpr modint& operator *= (const modint& x) {
        (val *= x.val) %= MOD;
        return *this;
    }
    constexpr modint& operator /= (const modint& x){
        return (*this) *= x.inv();
    }
    constexpr bool operator == (const modint& x) const {
        return this->val == x.val;
    }
    constexpr bool operator != (const modint& x) const {
        return this->val != x.val;
    }
    constexpr modint pow(ll t) const {
        if(t == 0) return 1;
        modint x = *this, res = 1;
        while(t > 0){
            if(t & 1) res *= x;
            x *= x;
            t >>= 1;
        }
        return res;
    }
    constexpr modint inv() const {
        ll a = val, b = MOD, u = 1, v = 0;
        while(b > 0){
            ll t = a / b;
            swap(a -= t * b, b);
            swap(u -= t * v, v);
        }
        return modint(u);
    }
    friend constexpr istream& operator >> (istream& is, modint& x) {
        is >> x.val;
        x.val %= MOD;
        if(x.val < 0) x.val += MOD;
        return is;
    }
    friend constexpr ostream& operator << (ostream& os, const modint& x) {
        return os << x.val;
    }
};

const int MOD = 998244353;
using mint = modint<MOD>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    // グラフ G の補グラフを入力
    vector<vector<int>> G(N);
    // 通行禁止の辺を管理(first < second)
    set<pair<int, int>> edge;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v, u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        edge.insert(minmax(u, v));
    }

    // 1 -> N への最短距離を求める
    // nseen := 未訪問の頂点集合
    // 本来の BFS だと Θ(N^2) だが, 未訪問の頂点集合を管理することで O((N + M)logM) にできる
    set<int> nseen;
    for(int i = 0; i < N; i++) nseen.insert(i);
    vector<int> dist(N, INF);
    queue<int> que;

    nseen.erase(0);
    dist[0] = 0;
    que.emplace(0);

    while(!que.empty()){
        int pos = que.front();
        que.pop();

        // イテレータ破壊対策: nseen2 に copy
        vector<int> nseen2(nseen.begin(), nseen.end());
        for(auto np: nseen2){
            if(edge.count(minmax(pos, np)) == 0){
                nseen.erase(np);
                dist[np] = dist[pos] + 1;
                que.emplace(np);
            }
        }
    }

    // 到達不可能の場合
    if(dist[N - 1] == INF){
        cout << -1 << '\n';
        return 0;
    }

    // 最短経路数を求める
    // dist の昇順に頂点を並べる
    vector<pair<int, int>> id(N);
    for(int i = 0; i < N; i++) id[i] = {dist[i], i};
    sort(id.begin(), id.end());

    // dp[i] := 頂点 i の最短経路数
    // sum[i] := 距離 i までの最短経路数の総和
    vector<mint> dp(N), sum(N);
    dp[0] = sum[0] = 1;
    for(int i = 1; i < N; i++){
        auto [d, pos] = id[i];
        if(d == INF) break; // pos が到達不可能ならこの後の頂点も到達不可能
        dp[pos] = sum[d - 1];
        // 通行禁止の頂点 np を全探索
        for(auto np: G[pos]){
            // 距離が d - 1 のとき sum[d - 1] に含まれている為 dp[np] を引く
            if(dist[np] == d - 1){
                dp[pos] -= dp[np];
            }
        }
        sum[d] += dp[pos];
    }

    cout << dp[N - 1] << '\n';
}