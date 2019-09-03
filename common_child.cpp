#include <bits/stdc++.h>

using namespace std;

// Complete the commonChild function below.
int commonChild(string s1, string s2) {
	int n = s1.length(), m = s2.length();
	int DP[2][m+1];
	for (int i = 0; i <= m; ++i){
		DP[0][i] = 0;
	}
	DP[1][0] = 0;

	for (int i = 1; i <= n; ++i){
		int p = i%2;
		for(int j = 1; j <= m; j++){
			if(s1[i-1] == s2[j-1]){
				DP[p][j] = 1 + DP[1-p][j-1];
			}
			else {
				DP[p][j] = max(DP[1-p][j], DP[p][j-1]);
			}
		}
		p = 1 - p;
	}
	cout << max(DP[0][m], DP[1][m]) << endl;
	return max(DP[0][m], DP[1][m]);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
