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
    int N;
    cin >> N;
    vector<vector<int>> G(N);
    for(int i = 0; i < N - 1; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<int> col(N, -1);
    queue<int> que;
    col[0] = 0;
    que.push(0);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(col[np] != -1) continue;
            col[np] = !col[pos];
            que.push(np);
        }
    }
    
    vector<int> col0, col1;
    for(int i = 0; i < N; i++){
        if(col[i] == 0) col0.push_back(i + 1);
        if(col[i] == 1) col1.push_back(i + 1);
    }

    if(col0.size() > col1.size()){
        for(int i = 0; i < N / 2; i++){
            cout << col0[i] << " \n"[i == N / 2 - 1];
        }
    }else{
        for(int i = 0; i < N / 2; i++){
            cout << col1[i] << " \n"[i == N / 2 - 1];
        }
    }
}