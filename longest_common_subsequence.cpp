#include <bits/stdc++.h>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, m;
    cin>>n>>m;
    int A[n], B[m];
    for(int i=0; i<n; i++)cin>>A[i];
    for(int i=0; i<m; i++)cin>>B[i];
    
    int T[n+1][m+1];
    for(int i=0; i<=n; i++)T[i][0] = 0;
    for(int i=0; i<=m; i++)T[0][i] = 0;
    for(int i=1; i<=n; i++){
        // cout << T[i][0] << " ";
        for(int j=1; j<=m; j++){
            if(A[i-1]==B[j-1]){
                T[i][j] = 1 + T[i-1][j-1];
            }
            else{
                T[i][j] = max(T[i-1][j], T[i][j-1]);
            }
            // cout << T[i][j] << " ";
        }
        // cout << end/l;
    }
    // cout << endl;
    vector<int> v;
    int k = 0;
    int i = n; 
    int j = m;
    while(j!=0 && i!=0 && T[i][j] > 0){
        // cout << i << " " << j << endl;
        if(T[i][j]==T[i-1][j]){
            i--;
        }
        else if(T[i][j] == T[i][j-1]){
            j--;
        }
        else if(T[i][j] - T[i-1][j-1] == 1){
            v.push_back(A[i-1]);
            i --;
            j--;
            continue;
        }
        
         
    }
    // cout << k << endl;
    for (i = v.size()-1; i >= 0; i--){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}
