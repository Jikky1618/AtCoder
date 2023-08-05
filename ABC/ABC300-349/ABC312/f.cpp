#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;

    vector<int> T(N), X(N);
    for(int i = 0; i < N; i++) cin >> T[i] >> X[i];

    // 缶切りが不要な缶, 必要な缶, 缶切りを分ける
    vector<int> A, B, C;
    for(int i = 0; i < N; i++){
        if(T[i] == 0) A.emplace_back(X[i]);
        if(T[i] == 1) B.emplace_back(X[i]);
        if(T[i] == 2) C.emplace_back(X[i]);
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    sort(C.begin(), C.end(), greater<int>());

    int a = A.size(), b = B.size(), c = C.size();
    // 開けれる缶の上位 M 個を管理
    SeparatedMultisetSum<ll> SMS;
    for(int i = 0; i < a; i++) SMS.insert_high(A[i]);
    // M 個に調整
    while(SMS.size_high() < M) SMS.insert_high(0);
    while(SMS.size_high() > M) SMS.decrease_high();

    debug(SMS.high);
    ll ans = SMS.sum_high();
    // 缶切りの使用個数を全探索
    int pos = 0;
    for(int i = 0; i < c; i++){
        for(int j = 0; j < C[i]; j++){
            if(pos == b) break;
            SMS.insert_high(B[pos]);
            pos++;
        }
        // M - 缶切りの個数 個になるように調整
        while(SMS.size_high() > max(0, M - i - 1)) SMS.decrease_high();
        ans = max(ans, SMS.sum_high());
    }

    cout << ans << endl;
}