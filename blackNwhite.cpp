#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool isValid(int n, int m, int x, int y) {
	if(x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}

long findPossibleWays(int n, int m, int x, int y) {
	int X[] = {1, 1, -1, -1, 2, -2, 2, -2};
	int Y[] = {2, -2, 2, -2, 1, 1, -1, -1};

	long attackedPoints = 0;
	for (int i = 0; i < 8; ++i){
		if(isValid(n, m, x + X[i], y + Y[i])){
			attackedPoints ++;
		}
	}
	long ans = n;
	ans *= m;
	return ans - attackedPoints;
}

int main(){
	int t; cin>>t;

	while(t--){
        int n, m;
        cin>>n>>m;

        long ans = -n;
		ans *= m;
        for (int i = 0; i < n; ++i){
        	for(int j = 0; j < m; j++){
        		ans += findPossibleWays(n, m, i, j);
        	}
        }
        cout << ans << endl;
	}

	return 0;
}