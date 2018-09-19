#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;

// Complete the knightlOnAChessboard function below.
bool isvalid(int x, int y, int n){
    if(x < 0 || y < 0 || y >= n || x >= n)
        return false;
    return true;
}
vector<vector<int>> knightlOnAChessboard(int n) {

    vector<vector<int> > A(n-1, vector<int>(n-1));

    for (int i = 1; i < n; ++i){
        for(int j = i; j < n; j++){
            vector<vector<int> > T(n, vector<int>(n, 1000000));
            T[0][0] = 0;
            vector<vector<bool> > visited(n, vector<bool>(n, false));

            int a = i, b = j;
            int P[8] = {a, a, -a, -a, b, b, -b, -b};
            int Q[8] = {b, -b, b, -b, a, -a, a, -a};
            if(i == 1 && j == 1)
                A[i-1][j-1] = n-1;
            else if(i > n/2){
                A[i-1][j-1] = -1;
                A[j-1][i-1] = -1;
            }
            else{
                visited[0][0] = true;
                queue<pii> que;
                que.push(mp(0, 0));

                while(!que.empty()){
                    pii f = que.front(); que.pop();
                    int x = f.first;
                    int y = f.second;
                    for(int k = 0; k < 8; k++){
                        int p = x + P[k];
                        int q = y + Q[k];
                        if(isvalid(p, q, n) && T[p][q] > 1 + T[x][y]){
                            T[p][q] = 1 + T[x][y];
                            T[q][p] = T[p][q];
                            if(!visited[p][q])
                                que.push(mp(p,q));
                        }
                    }
                }

                A[i-1][j-1] = (T[n-1][n-1] == 1000000)? -1 : T[n-1][n-1];
                A[j-1][i-1] = (T[n-1][n-1] == 1000000)? -1 : T[n-1][n-1];
            }
        }
    }
    A[n-2][n-2] = 1;
    return A;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
