#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int main(){
	int t; cin>>t;

	while(t--){
        int n;
        cin>>n;
        long A[n+1];
        A[0] = 1;
        for(int i = 1; i <= n; i++){
            if(i <= 2){
                A[i] = 1;
            }
            else if(i == 3){
                A[i] = 2;
            }
            else {
                A[i] = A[i-1] + A[i-3] + A[i-4];
            }
            A[i] = A[i]%M;
            cout << i << " -> " << A[i] << endl;
        }
        cout << A[n] << endl;
	}

	return 0;
}