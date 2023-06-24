#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// cf. https://atcoder.jp/contests/abc306/submissions/42333516
template <class T>
struct SeparatedMultisetSum {
    // nl := low 側のmultisetの要素数, nh := high 側のmultisetの要素数
    int nl, nh;
    // msl := 下位のmultiset, msh := 上位のmultiset
    multiset<T> msl, msh;
    // suml := msl の総和, sumh := msh の総和
    T suml, sumh;

    // 空で初期化
    SeparatedMultisetSum() : nl(0), nh(0), suml(T(0)), sumh(T(0)) {}

    // 多重集合が空かどうか
    bool empty_l() const { return nl == 0; }
    bool empty_h() const { return nh == 0; }
    // 多重集合の大きさを返す
    int size_l() const { return nl; }
    int size_h() const { return nh; }

    // 多重集合に値 x を追加する
    void insert_l(const T& x) {
        // high の要素数が 0 または high の最小値よりも小さいなら
        if (nh == 0 || x <= *msh.begin()) {
            // low に追加する
            msl.insert(x);
            suml += x;
        } else {
            // high の最小値を low に移して, x を high に入れる
            T val = *msh.begin();
            msl.insert(val);
            msh.erase(msh.begin());
            msh.insert(x);
            suml += val;
            sumh -= val, sumh += x;
        }
        nl++;
    }

    void insert_h(const T& x) {
        // low の要素数が 0 または low の最大値よりも大きいなら
        if (nl == 0 || x >= *msl.rbegin()) {
            // high に追加する
            msh.insert(x);
            sumh += x;
        } else {
            // low の最大値を high に移して, x を low に入れる
            T val = *msl.rbegin();
            msh.insert(val);
            msl.erase(prev(msl.end()));
            msl.insert(x);
            sumh += val;
            suml -= val, suml += x;
        }
        nh++;
    }
    // 多重集合の最大値 ・ 最小値を返す
    T max_l() const {
        return nl > 0 ? *msl.rbegin() : numeric_limits<T>::lowest();
    }
    T min_h() const { 
        return nh > 0 ? *msh.begin() : numeric_limits<T>::max();
    }
    // 多重集合内の値 val を削除する
    bool erase_l(const T& val) {
        if (nl == 0) return false;
        auto itr = msl.find(val);
        if (itr != msl.end()) {
            msl.erase(itr);
            suml -= val;
            nl--;
            return true;
        }

        itr = msh.find(val);
        if (itr != msh.end()) {
            T v = *msl.rbegin();
            msh.erase(itr);
            msh.insert(v);
            msl.erase(prev(msl.end()));
            suml -= v;
            sumh -= val - v;
            nl--;
            return true;
        }
        return false;
    }
    bool erase_h(const T& val) {
        if (nh == 0) return false;
        auto itr = msh.find(val);
        if (itr != msh.end()) {
            msh.erase(itr);
            sumh -= val;
            nh--;
            return true;
        }
        itr = msl.find(val);
        if (itr != msl.end()) {
            T v = *msh.begin();
            msl.erase(itr);
            msl.insert(v);
            msh.erase(msh.begin());
            sumh -= v;
            suml -= val - v;
            nh--;
            return true;
        }
        return false;
    }
    // 多重集合の和を返す
    T sum_l() const { return suml; }
    T sum_h() const { return sumh; }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K, Q;
    cin >> N >> K >> Q;

    SeparatedMultisetSum<ll> SMS;
    // 上位 K 番を high に入れる
    for (int i = 0; i < K; i++) SMS.insert_h(0);
    // 下位 N - K 番目を low に入れる
    for (int i = 0; i < N - K; i++) SMS.insert_l(0);

    vector<int> A(N);
    while (Q--) {
        int X, Y;
        cin >> X >> Y, X--;
        SMS.erase_h(A[X]);
        A[X] = Y;
        SMS.insert_h(A[X]);

        cout << SMS.sum_h() << "\n";
    }
}