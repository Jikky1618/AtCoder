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
    int HA, WA;
    cin >> HA >> WA;
    vector<string> A(HA);
    for(int i = 0; i < HA; i++) cin >> A[i];
    int HB, WB;
    cin >> HB >> WB;
    vector<string> B(HB);
    for(int i = 0; i < HB; i++) cin >> B[i];
    int HX, WX;
    cin >> HX >> WX;
    vector<string> X(HX);
    for(int i = 0; i < HX; i++) cin >> X[i];

    // ax, ay := A の左上の場所
    for(int ax = -HA; ax <= HX; ax++){
        for(int ay = -WA; ay <= WX; ay++){
            // bx, by := B の左上の場所
            for(int bx = -HB; bx <= HX; bx++){
                for(int by = -HB; by <= WX; by++){
                    // A, B を貼り付けた C を構築 (大きさは X )
                    vector<string> C(HX, string(WX, '.'));
                    bool flag = true; // flag := C に使われていない黒いマスがあるかどうか
                    for(int i = 0; i < HA; i++){
                        for(int j = 0; j < WA; j++){
                            if(A[i][j] == '#'){
                                if(0 <= ax + i && ax + i < HX && 0 <= ay + j && ay + j < WX){
                                    C[ax + i][ay + j] = '#';
                                }else{
                                    flag = false;
                                }
                            }
                        }
                    }
                    for(int i = 0; i < HB; i++){
                        for(int j = 0; j < WB; j++){
                            if(B[i][j] == '#'){
                                if(0 <= bx + i && bx + i < HX && 0 <= by + j && by + j < WX){
                                    C[bx + i][by + j] = '#';
                                }else{
                                    flag = false;
                                }
                            }
                        }
                    }

                    if(flag && C == X){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "No" << endl;
}