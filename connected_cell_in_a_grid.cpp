#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int> > grid, int i, int j, int n, int m, int &maxRegionLengthTemp){
    if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
        return;
    }
    maxRegionLengthTemp ++;
    grid[i][j] = 0;
    dfs(grid, i-1, j-1, n, m, maxRegionLengthTemp);
    dfs(grid, i-1, j, n, m, maxRegionLengthTemp);
    dfs(grid, i-1, j+1, n, m, maxRegionLengthTemp);
    dfs(grid, i, j-1, n, m, maxRegionLengthTemp);
    dfs(grid, i, j+1, n, m, maxRegionLengthTemp);
    dfs(grid, i+1, j-1, n, m, maxRegionLengthTemp);
    dfs(grid, i+1, j, n, m, maxRegionLengthTemp);
    dfs(grid, i+1, j+1, n, m, maxRegionLengthTemp);
}

// Complete the maxRegion function below.
int maxRegion(vector<vector<int> > grid) {
    int maxRegionLength = 0;
    int n = grid.size();
    int m = grid[0].size();


    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            int maxRegionLengthTemp = 0;
            if(grid[i][j] == 1){
                // maxRegionLengthTemp = 1;
                dfs(grid, i, j, n, m, maxRegionLengthTemp);
                maxRegionLength = max(maxRegionLength, maxRegionLengthTemp);
            }
        }
    }
    
    return maxRegionLength;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int> > grid(n);
    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}
