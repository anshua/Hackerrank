#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
#define M 1000000007
bool prime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

bool isChloe(int a, int b, int c, int d, int e){
    return prime(a + b + c) && prime(b + c + d) && prime(c + d + e) && 
        prime(a + b + c + d) && prime(b + c + d + e) && prime(a + b + c + d + e);
}

int main() {
    std::map<pii, int> chloe;
    for(int i = 1; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                for(int l = 0; l < 10; l++){
                    for(int m = 0; m < 10; m++){
                        if(isChloe(i,j,k,l,m)){
                            chloe[mp(j*1000+k*100+l*10+m, 1)] += 1;
                        }
                    }
                }
            }
        }
    }
    int q;
    int n; cin>>q>>n;
    while(q--){
        int flag = 1;
        while(n > 5){
            // cout << flag << endl;
            for(int j = 0; j < 10; j++){
                for(int k = 0; k < 10; k++){
                    for(int l = 0; l < 10; l++){
                        for(int m = 0; m < 10; m++){
                            for(int i = 0; i < 10; i++){
                                if(isChloe(j,k,l,m,i)){
                                    chloe[mp(k*1000+l*100+m*10+i, 1-flag)] += 
                                    chloe[mp(j*1000+k*100+l*10+m, flag)];
                                }    
                            }
                        }
                    }
                }
            }
            flag = 1 - flag;
            n--;
        }
        
        std::map<pii, int>::iterator i;
        int ans = 0;
        for(i = chloe.begin(); i != chloe.end(); i++){
            // cout << i->first.first << " " << i->first.second << " -> " << i->second << endl;
            if(i->first.second == flag){
                ans += i->second;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
