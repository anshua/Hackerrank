#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;
#define M 1000000007
#define N 400000

int D[N];

bool isPrime(int n){
    if(n < 2)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0)
            return false;
    }
    return true;   
}

int digitSum(int n){
    return (n == 0)? 0 : n%10 + digitSum(n/10);
}

bool isChloeNum4(int x){
    return  isPrime(digitSum(x%1000))
            && isPrime(digitSum(x/10))
            && isPrime(digitSum(x));           
}

bool isChloeNum(int x){
    return  isPrime(digitSum(x%1000))
            && isPrime(digitSum((x/10) % 1000))
            && isPrime(digitSum((x/100) % 1000))
            && isPrime(digitSum(x%10000))
            && isPrime(digitSum((x/10) % 10000))
            && isPrime(digitSum(x));           
}

long solve(int n) {
    int A[5] = {0, 9, 99, 303, 280};
    return A[n];
}

int main() {
    int t;
    cin>>t;

    int j = 0, n = 4;
    int Matrix[10000][N] = {0};
    D[1] = 9;
    D[2] = 90;
    D[3] = 303;
    D[4] = 280;
    std::map<int, int> m[2];
    for (int i = 1000; i < 10000; ++i){
        if(isChloeNum4(i)){
            m[0][i] = 1;
            m[1][i] = 0;
            j++;
        }
    }
    int flag = 1, p = 0, val;
    for (int i = 1000000; i < 10000000; ++i){
        if(isChloeNum(i/100) && isChloeNum(i%100000) && isChloeNum((i/10)%100000)) {
            p++;
        }
    }
    cout << p << endl;
    D[n] = j;
    n++;
    cout << j << endl;
    int ans;
    map<int,int>::iterator it;
    for (; n < 100; ++n){
        for (it = m[flag^1].begin(); it != m[flag^1].end(); ++it){
            p = it->first;
            val = it->second % M;
            for(int e = 0; e < 10; e++){
                int newP = p*10+e;
                if(isChloeNum(newP)){
                    m[flag][newP%10000] += val;
                }
            }
        }
        ans = 0;
        m[flag^1].clear();
        for (it = m[flag].begin(); it != m[flag].end(); ++it){
            ans += it->second;
            ans %= M;
        }
        D[n] = (ans+M)%M;
        flag ^= 1;
        if(n%1000 == 0){
            cout << n << endl;
        }
        // cout << n << " ";
    }
    cout << endl;

    for (int i = 1; i < 10; ++i){
        cout << i << " -> " << D[i] << endl;
    }
    while(t--){
        int n;
        cin>>n;
        cout << D[n] << endl;
    }
    
    return 0;
}
