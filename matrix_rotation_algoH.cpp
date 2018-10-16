#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

pii newPosition(int i, int j, int n, int m, int k){
    if(k == 0){
        return mp(i, j);
    }

    // left upper corner
    if(i - j == 0 && i+j <= n){
        if(i+j == n && n == m){
            return mp(i, j);
        }
        // right upper
        if(m - 2*j == 0){
            if(k <= n - 2*i){
                return mp(i + k, j);
            }
            else{
                return newPosition(n - i, j, n, m, k - (n - 2*i));
            }
        }

        if(k <= m - 2*j){
            return mp(i, j + k);
        }
        else{
            return newPosition(i, m - j, n, m, k - (m - 2 * j));
        }
    }
    // left down corner
    else if(i+j  == n && i >= j){
        // right down
        if(2*i - n  == 0){
            if(k <= 2*j - m){
                return mp(i, j - k);
            }
            else{
                return newPosition(i, m - j, n, m, k - (2*j - m));
            }
        }

        if(k <= 2*i - n){
            return mp(i - k, j);
        }
        else{
            return newPosition(n - i, j, n, m, k - (2*i - n));
        }
    }
    // right down corner
    else if(i - j == n - m && i + j > n && i + j > m){
        // left down
        if(2*j - m == 0){
            if(k <= 2*i - n){
                return mp(i - k, j);
            }
            else{
                return newPosition(n - i, j, n, m, k - (2*i - n));
            }
        }

        if(k <= 2*j - m){
            return mp(i, j - k);
        }
        else{
            return newPosition(i, m - j, n, m, k - (2*j - m));
        }
    }
    // right upper corner
    else if(i + j == m && j > i){
        // left upper
        if(n - 2*i == 0){
            if(k <= m - 2*j){
                return mp(i, j + k);
            }
            else{
                return newPosition(i, m - j, n, m, k - (m - 2 * j));
            }
        }
        if(k <= n - 2*i){
            return mp(i + k, j);
        }
        else{
            return newPosition(n - i, j, n, m, k - (n - 2*i));
        }
    }

    int left = j;
    int right = m - j;
    int up = i;
    int down = n - i;

    return mp(i, j);
}

// Complete the matrixRotation function below.
void matrixRotation(vector<vector<int>> matrix, int k) {
    int n = matrix.size();
    int m = matrix[0].size();
    cout << endl;
    for (int i = 0; i < n; ++i){
        for(int j = 0; j < m; j++){
            pii p = newPosition(i, j, n-1, m-1, k);
            cout << matrix[p.first][p.second] << " ";
        }
        cout << endl;
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
