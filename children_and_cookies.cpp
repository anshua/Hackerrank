#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int A[n];
	for (int i = 0; i < n; ++i)
		cin>>A[i];
	int T[n][2];
	T[0][0] = 0;
	T[0][1] = 0;
	for (int i = 1; i < n; ++i){
		// Assign value 1
		T[i][0] = max(T[i-1][0], T[i-1][1] + abs(A[i-1] - 1));

		// assing max value
		T[i][1] = max(T[i-1][0] + abs(A[i] - 1) , T[i-1][1] + abs(A[i] - A[i-1]));
	}

	cout << max(T[n-1][0], T[n-1][1]) << endl;
}
