#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    const string PI = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    int N;
    cin >> N;
    cout << PI.substr(0, N + 2) << endl;
}