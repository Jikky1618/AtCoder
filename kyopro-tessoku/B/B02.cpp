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
    int A, B;
    cin >> A >> B;

    bool flag = false;
    for(int i = A; i <= B; i++){
        if(100 % i == 0) flag = true;
    }

    cout << (flag ? "Yes" : "No") << endl;
}