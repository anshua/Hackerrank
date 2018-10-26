#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool isValid(int i, int j, int n, int m){
    if(i < 0 || j < 0 || i >= n || j >= m)
        return false;
    return true;
}
// Complete the bomberMan function below.
vector<string> bomberMan(int k, vector<string> A) {
    vector<string> v;
    int n = A.size();
    if(k <= 1)
        return A;
    if(k%2 == 0){
        for(int i = 0; i < A.size(); i++){
            string s = A[i];
            string p = "";
            int m = s.length();
            for(int j = 0; j < m; j++){
                p += "O";
            }
            v.push_back(p);
        }
        return v;
    }
    k = k%4;
    for(int i = 0; i < A.size(); i++){
        string s = A[i];
        string p = "";
        int m = s.length();
        for(int j = 0; j < m; j++){
            bool b = false;
            if(isValid(i-1, j, n, m) && A[i-1][j] == 'O'){
                b = true;
            }
            if(isValid(i+1, j, n, m) && A[i+1][j] == 'O'){
                b = true;
            }
            if(isValid(i, j-1, n, m) && A[i][j-1] == 'O'){
                b = true;
            }
            if(isValid(i, j+1, n, m) && A[i][j+1] == 'O'){
                b = true;
            }
            if(b || A[i][j] == 'O')
                p += ".";
            else{
                p += "O";
            }
        }
        v.push_back(p);
    }
    if(k == 3)
        return v;
    else
        return bomberMan(3, v);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
