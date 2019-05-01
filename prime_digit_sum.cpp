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

long value(long A[12]){
    long x = A[0]%M + (A[1]*5)%M + (A[2]*8)%M + A[3]%M + (A[4]*4)%M + (A[5]*11)%M + (A[6]*9)%M + 
            (A[7]*2)%M + (A[8]*2)%M + (A[9]*9)%M + (A[10]*4)%M + (A[11])%M;
    x = x%M;
    return x;
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
    int n; cin>>q;
    std::vector<int> v;
    int max_num = 0;
    while(q--){
        cin>>n;
        max_num = max(max_num, n);
        v.push_back(n);
    }

    long A[max_num+1] = {0};
    std::map<pii, int>::iterator i;

    int ans = 0;
    for (i = chloe.begin(); i != chloe.end(); ++i){
        ans += i->second;
    }

    A[5] = ans;
    ans = 0;
    long B[2][12] = {0};
    int p = 5;
    std::map<pii, int> chloe1[2];
    chloe1[1] = chloe;
    int flag = 1;
    while(p < max_num){
        p++;
            if(flag == 1){
                for(i = chloe1[1].begin(); i != chloe1[1].end(); i++){
                    int x = i->first.first;
                    int a, b, c, d;
                    a = x/1000;
                    b = (x%1000)/100;
                    c = (x%100)/10;
                    d = x%10;
                    for(int e = 0; e < 10; e++){
                        if(isChloe(a,b,c,d,e)){
                            chloe1[0][mp(b*1000+c*100+d*10+e, 1-flag)] += 
                            i->second;
                            chloe1[0][mp(b*1000+c*100+d*10+e, 1-flag)] %= M;
                        }
                    }
                }
                chloe1[1].clear();
            }
            else{
                for(i = chloe1[0].begin(); i != chloe1[0].end(); i++){
                    int x = i->first.first;
                    int a, b, c, d;
                    a = x/1000;
                    b = (x%1000)/100;
                    c = (x%100)/10;
                    d = x%10;
                    for(int e = 0; e < 10; e++){
                        if(isChloe(a,b,c,d,e)){
                            chloe1[1][mp(b*1000+c*100+d*10+e, 1-flag)] += 
                            i->second;
                            chloe1[1][mp(b*1000+c*100+d*10+e, 1-flag)] %= M;
                        }
                    }
                }
                chloe1[0].clear();
            }
            for (i = chloe1[1-flag].begin(); i != chloe1[1-flag].end(); ++i){
                A[p] += i->second;
                A[p] %= M;
            }

        
        // else{
        //     B[1-flag][0] = (B[flag][0]*2)%M;
        //     B[1-flag][1] = (B[flag][8])%M;
        //     B[1-flag][2] = (B[flag][9])%M;
        //     B[1-flag][3] = (B[flag][0] + B[flag][10] + B[flag][11])%M;
        //     B[1-flag][4] = (B[flag][0])%M;
        //     B[1-flag][5] = (B[flag][1] + B[flag][9])%M;
        //     B[1-flag][6] = (B[flag][1])%M;
        //     B[1-flag][7] = (B[flag][2])%M;
        //     B[1-flag][8] = (B[flag][3])%M;
        //     B[1-flag][9] = (B[flag][4])%M;
        //     B[1-flag][10] = (B[flag][5])%M;
        //     B[1-flag][11] = (B[flag][6])%M;
        //     A[p] = value(B[1-flag]);
        //     if(p == 39 || p == 40){
        //         for (int i1 = 0; i1 < 12; ++i1){
        //             cout << B[1-flag][i1] << " ";
        //             // B[1-flag][i1] = 
        //         }
        //         cout << endl << endl;
        //     }
            
        // }
        flag = 1 - flag;
        // if(p == 50){
        //     cout << " flag" << endl;
        //     B[0][0] = chloe1[flag][mp(20, flag)];
        //     B[0][1] = chloe1[flag][mp(30, flag)];
        //     B[0][2] = chloe1[flag][mp(122, flag)];
        //     B[0][3] = chloe1[flag][mp(200, flag)];
        //     B[0][4] = chloe1[flag][mp(201, flag)];
        //     B[0][5] = chloe1[flag][mp(300, flag)];
        //     B[0][6] = chloe1[flag][mp(304, flag)];
        //     B[0][7] = chloe1[flag][mp(9200, flag)];
        //     B[0][8] = chloe1[flag][mp(2003, flag)];
        //     B[0][9] = chloe1[flag][mp(2012, flag)];
        //     B[0][10] = chloe1[flag][mp(5002, flag)];
        //     B[0][11] = chloe1[flag][mp(5020, flag)];
        //     // cout << p <<  " ansu " <<  flag << endl;
        //     // for (int i1 = 0; i1 < 12; ++i1){
        //     //     cout << B[flag][i1] << " ";
        //     // }
        //     // cout << endl << endl;
            
        // }
    }

    for(int z = 0; z < v.size(); z++){
        cout << A[v[z]] << endl;
    }
    
    return 0;
}
