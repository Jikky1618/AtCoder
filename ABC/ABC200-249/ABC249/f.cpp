#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class T>
struct SeparatedMultisetSum {
    // nlow := low 側のmultisetの要素数, nhigh := high 側のmultisetの要素数
    int nlow, nhigh;
    // low := 下位のmultiset, high := 上位のmultiset
    multiset<T> low, high;
    // sumlow := low の総和, sumhigh := high の総和
    T sumlow, sumhigh;

    // 空で初期化
    SeparatedMultisetSum() : nlow(0), nhigh(0), sumlow(T(0)), sumhigh(T(0)) {}

    // 多重集合が空かどうか
    bool empty_low() const { return nlow == 0; }
    bool empty_high() const { return nhigh == 0; }
    // 多重集合の大きさを返す
    int size_low() const { return nlow; }
    int size_high() const { return nhigh; }
    // low 側の多重集合の最大値を返す
    T max_low() const {
        return nlow > 0 ? *low.rbegin() : numeric_limits<T>::lowest();
    }
    // high 側の多重集合の最小値を返す
    T min_high() const {
        return nhigh > 0 ? *high.begin() : numeric_limits<T>::max();
    }
    // 多重集合の和を返す
    T sum_low() const { return sumlow; }
    T sum_high() const { return sumhigh; }

    // low 側の多重集合に 1 つ要素を追加する
    void insert_low(const T& x) {
        // high の要素数が 0 または high の最小値よりも小さいなら
        if (nhigh == 0 || x <= *high.begin()) {
            // low に追加する
            low.insert(x);
            sumlow += x;
        } else {
            // high の最小値を low に移して, x を high に入れる
            T val = *high.begin();
            low.insert(val);
            high.erase(high.begin());
            high.insert(x);
            sumlow += val;
            sumhigh -= val, sumhigh += x;
        }
        nlow++;
    }
    // high 側の多重集合に 1 つ要素を追加する
    void insert_high(const T& x) {
        // low の要素数が 0 または low の最大値よりも大きいなら
        if (nlow == 0 || x >= *low.rbegin()) {
            // high に追加する
            high.insert(x);
            sumhigh += x;
        } else {
            // low の最大値を high に移して, x を low に入れる
            T val = *low.rbegin();
            high.insert(val);
            low.erase(prev(low.end()));
            low.insert(x);
            sumhigh += val;
            sumlow -= val, sumlow += x;
        }
        nhigh++;
    }
    // 多重集合内の値 val を削除する
    bool erase_low(const T& val) {
        if (nlow == 0) return false;
        auto itr = low.find(val);
        if (itr != low.end()) {
            low.erase(itr);
            sumlow -= val;
            nlow--;
            return true;
        }
        itr = high.find(val);
        if (itr != high.end()) {
            T v = *low.rbegin();
            high.erase(itr);
            high.insert(v);
            low.erase(prev(low.end()));
            sumlow -= v;
            sumhigh -= val - v;
            nlow--;
            return true;
        }
        return false;
    }
    bool erase_high(const T& val) {
        if (nhigh == 0) return false;
        auto itr = high.find(val);
        if (itr != high.end()) {
            high.erase(itr);
            sumhigh -= val;
            nhigh--;
            return true;
        }
        itr = low.find(val);
        if (itr != low.end()) {
            T v = *high.begin();
            low.erase(itr);
            low.insert(v);
            high.erase(high.begin());
            sumhigh -= v;
            sumlow -= val - v;
            nhigh--;
            return true;
        }
        return false;
    }
    // low 側の多重集合の大きさを 1 減らして, high 側の多重集合の大きさを 1 増やす
    void decrease_low() {
        if (nlow == 0) return;
        T v = *low.rbegin();
        low.erase(prev(low.end()));
        high.insert(v);
        sumlow -= v, sumhigh += v;
        nlow--, nhigh++;
    }
    // high 側の多重集合の大きさを 1 減らして, low 側の多重集合の大きさを 1 増やす
    void decrease_high() {
        if (nhigh == 0) return;
        T v = *high.begin();
        high.erase(high.begin());
        low.insert(v);
        sumhigh -= v, sumlow += v;
        nhigh--, nlow++;
    }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<int> t(N + 1);
    vector<ll> y(N + 1);
    for (int i = 1; i <= N; i++) cin >> t[i] >> y[i];
    t[0] = 1, y[0] = 0;

    ll ans = -INF, sum = 0;
    SeparatedMultisetSum<ll> SMS;

    // 代入操作を行ったとき, i番目以前の操作は値に全く関係なくなる
    // よって, どこで代入操作を行ったかで全探索
    // それ以降の操作によって最大化できる値を調べる
    for (int i = N; i >= 0; i--) {
        // 代入操作(それ以降の代入操作は全無視する)
        if (t[i] == 1) {
            // この時点で 負の加算操作での最小値 K 個は無視できる
            while (SMS.size_low() > K) {
                SMS.decrease_l();
            }
            // i 番目での代入操作での最大値は
            // sum := i番目以降の正の値の加算操作の総和
            // y[i] := 代入操作での値
            // SMS.sum_high() := 負の加算操作の最小値 K 個以外の総和
            // これらの和となる
            ll val = sum + y[i] + SMS.sum_high();
            debug(sum, y[i], SMS.sum_high());
            ans = max(ans, sum + y[i] + SMS.sum_high());
            // K = 0 なら, この再入操作は無視できないのでこれ以上最大化できない
            if (K == 0) break;
            // それ以降の代入操作は無視するので, この操作も無視するために K--
            K--;
        }
        if (t[i] == 2) {
            // 負なら, 多重集合に入れる
            if (y[i] < 0) SMS.insert_low(y[i]);
            // 正なら, 積極的に操作を行う
            else
                sum += y[i];
        }
    }

    cout << ans << endl;
}