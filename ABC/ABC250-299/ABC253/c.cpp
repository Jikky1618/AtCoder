#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;
    multiset<int> ms;
    for(int i = 0; i < Q; i++){
        int q; cin >> q;
        if(q == 1){
            int x; cin >> x;
            ms.insert(x);
        }
        if(q == 2){
            int x, c; cin >> x >> c;
            while(c > 0 && ms.find(x) != ms.end()){
                ms.erase(ms.find(x)); c--;
            }
        }
        if(q == 3){
            cout << *ms.rbegin() - *ms.begin() << endl;
        }
    }
    return 0;
}