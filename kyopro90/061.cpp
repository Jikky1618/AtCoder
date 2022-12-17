#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    deque<int> deck;
    while(Q--){
        int t, x; cin >> t >> x;
        if(t == 1) deck.push_front(x);
        if(t == 2) deck.push_back(x);
        if(t == 3) cout << deck[x - 1] << endl;
    }
    return 0;
}