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
class PersistentStack {
    struct Node {
        T val = -1;
        int size = 0;
        int prev = -1;
        Node(T v, int s, int p) : val(v), size(s), prev(p) {}
        Node() {}
    };

    int N;
    vector<Node> stk;

public:
    // 空の永続スタックで初期化
    PersistentStack() : N(1), stk(1) {}

    // t 番目のスタックのサイズの大きさを返す
    int size(int t) {
        assert(0 <= t && t < N);
        return stk[t].size;
    }
    int size() { return size(N - 1); }

    // t 番目のスタックが空かどうかを返す
    bool empty(int t) {
        assert(0 <= t && t < N);
        return t == 0;
    }
    bool empty() { return empty(N - 1); }

    // t 番目のスタックの先頭要素を返す
    T top(int t) {
        assert(0 <= t && t < N);
        assert(!empty()); // called PersistentStack::top on an empty stack
        debug(stk[t].val, stk[t].size, stk[t].prev);
        return stk[t].val;
    }
    T top() { return top(N - 1); }

    // t 番目のスタックに対し、x を先頭に追加したスタックを最新のスタックとして記録し、スタック番号を返す
    int push(T x, int t) {
        assert(0 <= t && t < N);
        stk.emplace_back(Node(x, stk[t].size + 1, t));
        return N++;
    }
    int push(T x) { return push(x, N - 1); }

    // t 番目のスタックに対し先頭要素を追加する前のスタック番号を返す
    int pop(int t) {
        assert(0 <= t && t < N);
        assert(!empty()); // called PersistentStack::top on an empty stack
        return stk[t].prev;
    }
    int pop() { return pop(N - 1); }
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;
    map<int, int> mp;
    PersistentStack<int> stk;
    int id = 0;

    while (Q--) {
        string t;
        cin >> t;
        if (t == "ADD") {
            int x;
            cin >> x;
            id = stk.push(x, id);
        }
        if (t == "DELETE") {
            if (!stk.empty(id)) id = stk.pop(id);
        }
        if (t == "SAVE") {
            int y;
            cin >> y;
            mp[y] = id;
        }
        if (t == "LOAD") {
            int z;
            cin >> z;
            id = mp[z];
        }

        cout << (stk.empty(id) ? -1 : stk.top(id)) << " \n"[Q == 0];
    }
}