#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<string> T = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    bool flag = false;
    for (auto s : T) {
        if (s == S) flag = true;
    }

    cout << (flag ? "Yes" : "No") << endl;
}