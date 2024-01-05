#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

uint_fast64_t random_number(uint_fast64_t l, uint_fast64_t r) {
    uint_fast64_t seed = chrono::duration_cast<chrono::milliseconds>(
                             chrono::system_clock::now().time_since_epoch())
                             .count();
    static mt19937_64 engine(seed);
    uniform_int_distribution<uint_fast64_t> rand(l, r);
    return rand(engine);
}

uint_fast32_t xorshift32(uint_fast32_t x) {
    x ^= x << 11;
    x ^= x >> 17;
    x ^= x << 13;
    return x;
}

struct RollingHash {
    using size_type = uint_fast32_t;
    using u64 = uint_fast64_t;
    using i128 = __int128_t;
    static constexpr size_type INF = numeric_limits<size_type>::max();
    static constexpr u64 MOD = (1ULL << 61) - 1;
    static u64 base;
    vector<u64> hash, pow;

    u64 mul(i128 a, i128 b) const {
        i128 t = a * b;
        t = (t >> 61) + (t & MOD);
        if (t >= MOD) t -= MOD;
        return t;
    }

    RollingHash(const string& S) : hash(S.size() + 1, 0), pow(S.size() + 1, 1) {
        for (size_type i = 0; i < S.size(); i++) {
            hash[i + 1] = mul(hash[i], base) + xorshift32(S[i] + 1);
            pow[i + 1] = mul(pow[i], base);
            if (hash[i + 1] >= MOD) hash[i + 1] -= MOD;
        }
    }
    // S[l, r) のハッシュ値を取得
    u64 get(size_type l, size_type r) const {
        u64 val = MOD + hash[r] - mul(hash[l], pow[r - l]);
        return val < MOD ? val : val - MOD;
    }
    // S のハッシュ値を取得
    u64 get() const { return hash.back(); }
    // ある区間(hash h1) の後ろに長さ h2len のある区間(hash
    // h2)を連結したハッシュ値を取得
    u64 connect(u64 h1, u64 h2, size_type h2len) const {
        u64 val = mul(h1, pow[h2len]) + h2;
        return val < MOD ? val : val - MOD;
    }
    // T を新たに連結する
    void connect(const string& T) {
        size_type N = hash.size(), M = T.size();
        hash.resize(N + M + 1), pow.resize(N + M + 1);
        for (size_type i = N; i < N + M; i++) {
            hash[i + 1] = mul(hash[i], base) + xorshift32(T[i - N] + 1);
            pow[i + 1] = mul(pow[i], base);
            if (hash[i + 1] >= MOD) hash[i + 1] -= MOD;
        }
    }
    // S[sl, sr) と T[tl, tr) の最長共通接尾辞の長さを求める
    size_type lcp(const RollingHash& T, size_type sl, size_type tl,
                  size_type sr = INF, size_type tr = INF) const {
        if (sr == INF) sr = hash.size();
        if (tr == INF) tr = T.hash.size();
        size_type len = min(sr - sl, tr - tl);
        size_type low = 0, high = len + 1;
        while (high - low > 1) {
            size_type mid = (low + high) >> 1;
            if (get(sl, sl + mid) == T.get(tl, tl + mid)) {
                low = mid;
            } else {
                high = mid;
            }
        }
        return low;
    }
};

RollingHash::u64 RollingHash::base = random_number(2, RollingHash::MOD - 2);

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int M = 0;
    for(int i = 0; i < N; i++) M = max(M, int(S[i].size()));


    // cnt[i][h] := prefix が i 文字の文字列のハッシュが h のものである文字列の id の集合
    vector<map<ll, set<int>>> cnt(M + 1);
    for(int i = 0; i < N; i++){
        RollingHash rh(S[i]);
        for(int j = 1; j <= int(S[i].size()); j++){
            cnt[j][rh.get(0, j)].insert(i);
        }
    }

    vector<int> ans(N);
    for(int i = 1; i <= M; i++){
        debug(cnt[i]);
        for(auto&& [key, val]: cnt[i]){
            if(int(val.size()) <= 1) continue;
            for(auto&& id: val) ans[id] = i;
        }
    }

    for(int i = 0; i < N; i++) cout << ans[i] << '\n';
}