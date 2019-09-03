#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
#define pii pair<int, int>
#define ppii pair<pii, pii>
#define mp make_pair


void dfs(vector<string> &grid, vector<ppii> tunnles, int i, int j, vector<vector<double> > &prob, vector<vector<bool> > &visited){
    if(grid[i][j] == '#'){
        return;
    }
    
    visited[i][j] = true;
}

int main()
{
    string nmk_temp;
    getline(cin, nmk_temp);

    vector<string> nmk = split_string(nmk_temp);

    int n = stoi(nmk[0]);

    int m = stoi(nmk[1]);

    int k = stoi(nmk[2]);

    std::vector<string> grid;

    vector<vector<double> > prob(n, vector<double> (m));
    vector<vector<bool> > visited(n, vector<bool> (m));

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string row;
        getline(cin, row);
        
        // Write Your Code Here
        grid.push(row);
    }

    std::vector<ppii> tunnles;

    for (int k_itr = 0; k_itr < k; k_itr++) {
        string i1J1I2J2_temp;
        getline(cin, i1J1I2J2_temp);

        vector<string> i1J1I2J2 = split_string(i1J1I2J2_temp);

        int i1 = stoi(i1J1I2J2[0]);

        int j1 = stoi(i1J1I2J2[1]);

        int i2 = stoi(i1J1I2J2[2]);

        int j2 = stoi(i1J1I2J2[3]);

        // Write Your Code Here
        tunnles.push(mp(mp(i1, j1), mp(i2, j2)));
    }
    // Write Your Code Here
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'A'){
                prob[i][j] = 1;
                dfs(grid, tunnles, i, j, pro, visited);
            }
        }
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
