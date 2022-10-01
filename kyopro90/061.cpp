#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    vector<int> t(q),x(q);
    for(int i = 0; i < q; i++) cin >> t[i] >> x[i];

    deque<int> deck;
    for(int i = 0; i < q; i++){
        if(t[i] == 1) deck.push_front(x[i]);
        if(t[i] == 2) deck.push_back(x[i]);
        if(t[i] == 3) cout << deck[x[i] - 1] << endl;
    }
    return 0;
}