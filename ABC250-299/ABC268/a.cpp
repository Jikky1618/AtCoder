#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    set<int> num;
    for(int i = 0; i < 5; i++){
        int N;
        cin >> N;
        num.insert(N);
    }
    cout << num.size() << endl;
    return 0;
}