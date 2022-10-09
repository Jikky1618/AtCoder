#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int g_1(int x){
    string s = to_string(x);
    sort(s.begin(), s.end(), greater<int>());
    return stoi(s);
}

int g_2(int x){
    string s = to_string(x);
    sort(s.begin(), s.end());
    return stoi(s);
}

int f(int x){
    return g_1(x) - g_2(x);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    for(int i = 0; i < k; i++){
        n = f(n);
    }

    cout << n << endl;
    return 0;
}